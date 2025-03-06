#include "minishell.h"

void	print_env(t_env *env)
{
	while (env)
	{
		printf("%s\n", env->env_str);
		env = env->next;
	}
}