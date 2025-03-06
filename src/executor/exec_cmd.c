#include "minishell.h"

static char	*get_cmd_path(t_shell shell, char *cmd)
{
	char	*cmd_path;

	cmd_path = resolve_command_path(cmd, shell.env);
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		shell.last_exit_code = 127;
		return (NULL);
	}
	return (cmd_path);
}

static void	execute_command(char *cmd_path, char **cmd_args, t_env *env)
{
	char	**envp;

	//signal(SIGINT, SIG_DFL); later needet
	//signal(SIGQUIT, SIG_DFL); later needet
	envp = env_list_to_array(env);
	if (!envp)
		exit(EXIT_FAILURE);
	execve(cmd_path, cmd_args, envp);
	perror("execve");
	exit(127);
}


/*
** exec_cmd:
** Forks a child process and executes a command.
*/
void	exec_cmd(t_shell shell)
{
	t_ast	*node;
	pid_t	pid;
	char	*cmd_path;

	node = shell.ast;
	cmd_path = get_cmd_path(shell, node->cmd_args[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return ;
	}
	if (pid == 0)
		execute_command(cmd_path, node->cmd_args, shell.env);
	free(cmd_path);
	waitpid(pid, NULL, 0);
}
