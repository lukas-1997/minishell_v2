#include "minishell.h"

/*
** exec_and:
** Executes a logical AND (&&) node.
** Executes the left command. If it succeeds (exit code 0),
** then the right command is executed.
*/
void	exec_and(t_shell shell)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		shell.ast = shell.ast->left;
		exec_ast(shell);
		exit(shell.last_exit_code);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		shell.ast = shell.ast->right;
		exec_ast(shell);
	}
}