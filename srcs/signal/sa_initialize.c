#include "minishell.h"

void	sa_initialize(int signal_number, struct sigaction *sa)
{
	if (sigemptyset(&sa->sa_mask) == -1)
	{
		fatal_error("sigemptyset");
	}
	if (sigaction(signal_number, sa, NULL) == -1)
	{
		fatal_error("sigaction");
	}
}
