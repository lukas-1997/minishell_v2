#include "minishell.h"

/*
** free_tokens:
** Frees all tokens in a linked list.
** - Iterates through the list
** - Frees each token's value
** - Frees the token structure itself
*/

void	free_tokens(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head->next;
		//printf("Freeing token: %s\n", head->value);
		free(head->value);
		free(head);
		head = tmp;
	}
	//printf("All tokens freed!\n");
}
