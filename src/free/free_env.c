#include "minishell.h"

/**
 * @brief Frees the entire linked list representing the environment variables.
 *
 * This function iterates through the linked list of `t_env` nodes, freeing
 * both the `env_str` string and the node itself. This ensures that all memory
 * allocated for the environment list is correctly released to prevent leaks.
 *
 * @param env A pointer to the first node of the environment list.
 */

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->env_str);
		free(env);
		env = tmp;
	}
}