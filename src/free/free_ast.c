#include "minishell.h"

void	free_ast(t_ast *node)
{
	if (!node)
		return ;
	free_ast(node->left);
	free_ast(node->right);
	//printf("Freeing AST node\n");

	if (node->cmd_args)
	{
		int i = 0;
		while (node->cmd_args[i])
		{
			//printf("Freeing cmd arg: %s\n", node->cmd_args[i]);
			free(node->cmd_args[i]);
			i++;
		}
		free(node->cmd_args);
	}
	free(node->redir_file);
	free(node);
	//printf("AST node freed!\n");
}
