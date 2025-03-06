#include "minishell.h"

/*
** exec_redir:
** Executes a redirection node.
** Opens the target file and redirects STDOUT to it.
** Then calls exec_ast() to execute the actual command.
*/
void	exec_redir(t_shell shell)
{
	t_ast	*redir;
	int		fd;

	redir = shell.ast;
	if (redir->append)
		fd = open(redir->redir_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(redir->redir_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("minishell");
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	shell.ast = redir->left;
	exec_ast(shell);
}
