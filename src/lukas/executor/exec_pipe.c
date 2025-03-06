#include "minishell.h"

static void	child_left_process(t_shell shell, t_ast *node, int pipefd[2])
{
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	shell.ast = node->left;
	exec_ast(shell);
	exit(EXIT_FAILURE);
}

static void	child_right_process(t_shell shell, t_ast *node, int pipefd[2])
{
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	shell.ast = node->right;
	exec_ast(shell);
	exit(EXIT_FAILURE);
}

static void	close_pipe_and_wait(int pipefd[2], pid_t pid1, pid_t pid2)
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

/*
** exec_pipe
** Executes a pipe operation between two commands.
** - Creates a pipe
** - Forks two child processes
*/
void	exec_pipe(t_shell shell)
{
	t_ast	*node;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	node = shell.ast;
	if (pipe(pipefd) < 0)
		return ;
	pid1 = fork();
	if (pid1 == 0)
		child_left_process(shell, node, pipefd);
	pid2 = fork();
	if (pid2 == 0)
		child_right_process(shell, node, pipefd);
	close_pipe_and_wait(pipefd, pid1, pid2);
}
