#include "minishell.h"

int	is_builtin(char *cmd)
{
	(void)cmd;
	// if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo"))
	// 	return (1);
	// if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export"))
	// 	return (1);
	// if (!ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env"))
	// 	return (1);
	// if (!ft_strcmp(cmd, "exit"))
	// 	return (1);
	return (0);
}

int	exec_builtin(t_ast *node, t_shell *shell)
{
	(void)node;
	(void)shell;
	// if (!ft_strcmp(node->cmd_args[0], "cd"))
	// 	return (builtin_cd(node->cmd_args, shell));
	// if (!ft_strcmp(node->cmd_args[0], "echo"))
	// 	return (builtin_echo(node->cmd_args));
	// if (!ft_strcmp(node->cmd_args[0], "exit"))
	// 	return (builtin_exit(node->cmd_args, shell));
	return (1);
}