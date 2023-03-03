#include "minishell.h"

t_node	*new_node(t_node_kind kind)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (node == NULL)
	{
		fatal_error("ft_calloc");
	}
	node->kind = kind;
	node->input_fd = STDIN_FILENO;
	node->output_fd = STDOUT_FILENO;
	return (node);
}
