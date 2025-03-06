/* minishell.h */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

# include "../lib/libft/libft.h"

/*----------------- ERROR -----------------*/

typedef enum e_error
{
	ERR_NONE = 0,
	ERR_MALLOC,
	ERR_SYNTAX,
	ERR_CMD_NOT_FOUND,
	ERR_PERMISSION,
	ERR_FILE_NOT_FOUND,
	ERR_PIPE,
	ERR_FORK,
	ERR_SIGNAL,
	ERR_UNKNOWN
}	t_error;
/*----------------- TOKEN -----------------*/

typedef enum e_toktype
{
	TOK_WORD,
	TOK_PIPE,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_APPEND,
	TOK_HEREDOC,
	TOK_AND,
	TOK_OR,
	TOK_LPAREN,     ////addet
	TOK_RPAREN,      ////addet
	TOK_SEMICOLON    ////addet
}	t_toktype;

typedef struct s_token
{
	char			*value;
	t_toktype		type;
	struct s_token	*next;
}	t_token;

/*----------------- AST -----------------*/

typedef enum e_asttype
{
	AST_CMD,
	AST_PIPE,
	AST_REDIR,
	AST_AND,
	AST_OR,
	AST_SUBSHELL,    ///() brackets
	AST_SEQ         ///AST_SEQ represents the semicolon operator (;) in shell commands This is different from && or ||, which depend on the success/failure of the first command.
}	t_asttype;

typedef struct s_ast
{
	t_asttype		type;
	char			**cmd_args;
	char			*redir_file; ///redir maybe 2d pointer (can have multiple redirs)
	int				append;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

/*----------------- ENV -----------------*/

typedef struct s_env
{
	char			*env_str;
	struct s_env	*next;
}	t_env;

/*----------------- SHELL CONTEXT -----------------*/

typedef struct s_shell
{
	t_token	*tokens;
	t_ast	*ast;
	t_env	*env;
	int		last_exit_code;
}	t_shell;

/*--------- dummy ---------*/
t_token *build_dummy_tokens(int case_num);
t_ast	*parse_tokens(t_token *tokens);

/*------------execution-----*/
void	exec_ast(t_shell shell);
void	exec_cmd(t_shell shell);
void	exec_pipe(t_shell shell);
void	exec_redir(t_shell shell);
void	exec_and(t_shell shell);
void	exec_or(t_shell shell);
int	is_builtin(char *cmd);
int	exec_builtin(t_ast *node, t_shell *shell);

/*--------- free ---------*/
void	free_ast(t_ast *root);
void	free_tokens(t_token *head);
void	free_env(t_env *env);

/*--------- env ---------*/
t_env *init_env(char **envp);
char    **env_list_to_array(t_env *env);
char	*resolve_command_path(char *cmd, t_env *env);

/*--------- remove ---------*/
void print_env(t_env *env);


#endif
