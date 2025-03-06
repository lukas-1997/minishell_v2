#include "minishell.h"


/*
** exec_ast:
** Recursively executes an AST (Abstract Syntax Tree) node.
** - If the node is a command, it executes the command
** - If the node is a pipe, it executes the pipe operation
*/

void	exec_ast(t_shell shell)
{
	if (!shell.ast)
		return ;
	if (shell.ast->type == AST_CMD)
		exec_cmd(shell);
	else if (shell.ast->type == AST_PIPE)
		exec_pipe(shell);
	else if (shell.ast->type == AST_REDIR)
		exec_redir(shell);
	else if (shell.ast->type == AST_AND)
		exec_and(shell);
	else if (shell.ast->type == AST_OR)
		exec_or(shell);
}
