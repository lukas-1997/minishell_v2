#include "minishell.h"

char    **env_list_to_array(t_env *env)
{
    int     size = 0;
    t_env   *tmp = env;
    char    **envp;

    // Count number of environment variables
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }

    // Allocate memory for envp array (+1 for NULL termination)
    envp = (char **)malloc(sizeof(char *) * (size + 1));
    if (!envp)
        return NULL;

    // Fill envp array with env_str values
    tmp = env;
    for (int i = 0; i < size; i++)
    {
        envp[i] = tmp->env_str;  // Directly store pointer to "VAR=VALUE"
        tmp = tmp->next;
    }
    envp[size] = NULL;  // Null-terminate the array

    return envp;
}
