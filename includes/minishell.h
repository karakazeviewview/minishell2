#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <unistd.h>
# include <signal.h>
# include "libft.h"

# define ERROR_TOKENIZE 258
# define ERROR_PARSE 258
# define ERROR_OPEN_REDIR 1
# define SIZE_OPERATORS_LIST 13
# define SINGLE_QUOTE_CHAR '\''
# define DOUBLE_QUOTE_CHAR '"'

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define END "\x1b[39m"

typedef enum s_token_kind	t_token_kind;
typedef enum s_node_kind	t_node_kind;
typedef struct s_minishell	t_minishell;
typedef struct s_token		t_token;
typedef struct s_node		t_node;
typedef struct s_env		t_env;

extern t_minishell			g_minishell;

typedef enum s_token_kind {
	TK_WORD,
	TK_RESERVED,
	TK_OPERATOR,
	TK_EOF
}	t_token_kind;

typedef enum s_node_kind {
	NODE_PIPELINE,
	NODE_SIMPLE_CMD,
	NODE_REDIR_OUT,
	NODE_REDIR_IN
}	t_node_kind;

typedef struct s_minishell {
	unsigned int			last_status;
	bool					syntax_error;
	bool					readline_interrupted;
	volatile sig_atomic_t	sig;
	t_env					*env;
}	t_minishell;

typedef struct s_env
{
	char	*name;
	char	*value;
	t_env	*next;
}	t_env;

typedef struct s_token {
	char			*word;
	t_token_kind	kind;
	int				file_fd;
	int				stashed_file_fd;
	t_token			*next;
}	t_token;

typedef struct s_node {
	t_node_kind	kind;
	t_node		*command;
	t_token		*args;
	t_node		*redirects;
	int			input_fd;
	int			output_fd;
	t_node		*next;
}	t_node;

// signal
void	setup_signals(void);
void	reset_signal_handler(void);
int		check_signal(void);
void	sa_initialize(int signal_number, struct sigaction *sa);

// map
void	env_init(void);
bool	is_identifier(const char *str);
char	*get_env(t_env *env, char *name);
void	add_env(t_env *env, char *name, char *value);
int		env_set(const char *name, const char *value);
int		env_unset(t_env *env, char *name);
int		env_put(char *string, bool e_value);
int		env_put2(char **value, char *string, bool e_value);
int		env_set(const char *name, const char *value);
t_env	*envnew(void);
void	add_back(t_env **lst, t_env *new);
void	env_free(t_env *env);

// error_func
void	fatal_error(const char *message) __attribute__((noreturn));
void	error_message(const char *location, const char *message,
			int status) __attribute__((noreturn));
void	assert_error(const char *message) __attribute__((noreturn));
void	tokenize_error(char *location, char **rest, char *line);
void	parse_error(const char *location, t_token **rest, t_token *token);
void	builtin_error(const char *func, const char *name, const char *err);
void	xperror(const char *location);

// destructor
void	frees_argv(char **argv);
void	list_frees_token(t_token *token);
void	list_frees_node(t_node *node);

// tokenize
t_token	*tokenize(char *line);
bool	is_blank(char c);
bool	is_meta_character(const char c);
t_token	*new_token(t_token_kind kind, char *word);
t_token	*new_token_type_word(char **rest, char *line);
t_token	*new_token_type_operator(char **rest, char *line);

// parse.c
t_node	*parse(t_token *token);
t_node	*new_node(t_node_kind kind);
t_token	*token_dup(t_token *source);
bool	at_eof(t_token_kind kind);
void	append_args(t_token **args, t_token *add_token);
void	append_redirects(t_node **redir, t_token *add_token, t_node_kind kind);
void	list_add_back(t_node **redir, t_token *add_token, t_node_kind kind);
void	try_append_redirect(t_node *node, t_token **rest, t_token *token);

// expand.c
bool	is_alpha_underscore(const char c);
bool	is_alnum_underscore(const char c);
bool	is_variable(const char *str);
bool	is_special_parameter(const char *str);
void	add_character(char **word, char c);
void	try_remove_quote(t_token *token);
void	append_variable(char **new_word, char **rest, char *current_word);
void	append_special_param(char **new_word, char **rest, char *current_word);
t_node	*expand(t_node *node);

// redirect.c
int		stash_fd(int fd);
int		open_redir_file(t_node *node);
void	redirect_file(t_node *command);
void	reset_redirect_command(t_node *command);
void	closes_redirect_file(t_node *node);
int		read_here_document(t_token *token);
void	reset_redirect_command(t_node *command);
void	reset_redirect_builtin(t_node *command);

// pipe
void	prepare_pipe(int *pipe_fd);
void	prepare_pipe_child(t_node *node, int *pipe_fd, int *prev_fd);
void	prepare_pipe_parent(int *pipe_fd);

// builtin
bool	is_builtin(t_node *node);
int		exec_builtin(t_node *node);
int		builtin_exit(char **argv);
int		builtin_cd(char **argv);
char	*set_oldpwd(void);
int		return_buildin_error(void);
int		builtin_echo(char **argv);
int		builtin_env(char **argv);
int		builtin_exit(char **argv);
int		builtin_export(char **argv);
int		builtin_pwd(char **argv);
int		builtin_unset(char **argv);

// interpret
int		interpret(t_node *node);
char	*search_path(const char *file_name);
char	*create_path(char *word);
char	**create_argv(char *path, t_token *token);
char	**create_env(t_env *env);
char	**create_builtin_argv(t_token *args);
int		exec_pipeline(t_node *node, int *prev_fd);

#endif
