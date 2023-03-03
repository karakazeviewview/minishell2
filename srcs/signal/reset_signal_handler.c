#include "minishell.h"

static void	default_signal_handler(int signal_number)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_flags = 0;
	sa.sa_handler = SIG_DFL;
	sa_initialize(signal_number, &sa);
}

void	reset_signal_handler(void)
{
	default_signal_handler(SIGINT);
	default_signal_handler(SIGQUIT);
}
