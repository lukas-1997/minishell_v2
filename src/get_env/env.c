#include "minishell.h"

//Function to Create a New Env Variable Node
static t_env	*create_env_node(char *env)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->env_str = strdup(env); // Store "KEY=VALUE"
	new_node->next = NULL;
	return (new_node);
}

//Function to Initialize the Env List
t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	*current;
	t_env	*new_node;

	head = NULL;
	current = NULL;
	while (*envp)
	{
		new_node = create_env_node(*envp);
		if (!new_node)
			return (NULL); // Handle memory errors properly
		if (!head)
			head = new_node;
		else
			current->next = new_node;
		current = new_node;
		envp++;
	}
	return (head);
}
