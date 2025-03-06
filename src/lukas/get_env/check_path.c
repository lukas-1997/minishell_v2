#include "minishell.h"

/*
** get_path_variable:
** Fetches the PATH variable from t_env list.
*/
static char	*get_path_variable(t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->env_str, "PATH=", 5) == 0)
			return (env->env_str + 5);
		env = env->next;
	}
	return (NULL);
}
/*
** free_array:
** Frees a NULL-terminated string array.
*/
static void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/*
** ft_strjoin_three:
** Joins three strings into one.
*/
static char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, s3);
	free(temp);
	return (result);
}

/*
** resolve_command_path:
** Resolves the full path to a command using PATH.
** Handles absolute and relative commands directly.
*/
char	*resolve_command_path(char *cmd, t_env *env)
{
	char	**paths;
	char	*full_path;
	int		i;

	if (cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	paths = ft_split(get_path_variable(env), ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin_three(paths[i], "/", cmd);
		if (access(full_path, X_OK) == 0)
			return (free_array(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_array(paths), NULL);
}