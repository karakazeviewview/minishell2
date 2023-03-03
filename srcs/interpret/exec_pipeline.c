#include "minishell.h"

t_minishell	g_minishell;

static void	do_child(t_node *node, int *pipe_fd, int *prev_fd)
{
	char	**env;
	char	**argv;
	char	*path;

	argv = NULL;
	path = NULL;
	env = NULL;
	reset_signal_handler();
	prepare_pipe_child(node, pipe_fd, prev_fd);
	if (is_builtin(node))
	{
		exit(exec_builtin(node));
	}
	else
	{
		redirect_file(node->command);
		path = create_path(node->command->args->word);
		argv = create_argv(path, node->command->args);
		env = create_env(g_minishell.env);
		execve(path, argv, env);
		env_free(g_minishell.env);
		reset_redirect_command(node->command);
		fatal_error("execve");
	}
}

int	exec_pipeline(t_node *node, int *prev_fd)
{
	pid_t			pid;
	int				pipe_fd[2];

	if (node == NULL)
		return (-1);
	prepare_pipe(pipe_fd);
	pid = fork();
	if (pid < 0)
		fatal_error("fork");
	else if (pid == 0)
	{
		do_child(node, pipe_fd, prev_fd);
	}
	else
	{
		prepare_pipe_parent(pipe_fd);
		exec_pipeline(node->next, pipe_fd);
		if (pipe_fd[0] != STDIN_FILENO)
			if (close(pipe_fd[0]) < 0)
				assert_error("close");
	}
	return (pid);
}
