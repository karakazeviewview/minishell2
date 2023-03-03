#include "minishell.h"

static void	check_wstatus(int *status, int wstatus)
{
	if (WIFSIGNALED(wstatus))
	{
		*status = 128 + WTERMSIG(wstatus);
	}
	else
	{
		*status = WEXITSTATUS(wstatus);
	}
}

int	wait_pipeline(pid_t last_pid)
{
	pid_t	wait_result;
	int		status;
	int		wstatus;

	status = 0;
	wstatus = 0;
	while (1)
	{
		wait_result = wait(&wstatus);
		if (wait_result == last_pid)
			check_wstatus(&status, wstatus);
		else if (wait_result < 0)
		{
			if (errno == ECHILD)
				break ;
			else if (errno == EINTR)
				continue ;
			else
				fatal_error("wait");
		}
	}
	return (status);
}

int	interpret(t_node *node)
{
	int		status;
	int		pipe_fd[2];
	pid_t	last_pid;

	status = 0;
	pipe_fd[0] = STDIN_FILENO;
	pipe_fd[1] = STDOUT_FILENO;
	if (open_redir_file(node) < 0)
	{
		return (ERROR_OPEN_REDIR);
	}
	if (node->next == NULL && is_builtin(node))
	{
		status = exec_builtin(node);
	}
	else
	{
		last_pid = exec_pipeline(node, pipe_fd);
		status = wait_pipeline(last_pid);
		closes_redirect_file(node);
	}
	return (status);
}
