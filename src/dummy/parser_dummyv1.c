// /* parser_dummy.c */

// #include "minishell.h"

// static t_ast	*new_ast_node(t_asttype type)
// {
// 	t_ast *node = malloc(sizeof(t_ast));
// 	if (!node)
// 		return (NULL);
// 	node->type = type;
// 	node->cmd_args = NULL;
// 	node->redir_file = NULL;
// 	node->append = 0;
// 	node->left = NULL;
// 	node->right = NULL;
// 	return (node);
// }

// t_ast	*parse_tokens(t_token *tokens)
// {
// 	(void)tokens;
// 	/* We'll assume: ls -l | grep c */
// 	t_ast *pipe_node = new_ast_node(AST_PIPE);
// 	t_ast *left_cmd = new_ast_node(AST_CMD);
// 	t_ast *right_cmd = new_ast_node(AST_CMD);

// 	left_cmd->cmd_args = (char **)malloc(sizeof(char *) * 3);
// 	left_cmd->cmd_args[0] = strdup("ls");
// 	left_cmd->cmd_args[1] = strdup("-l");
// 	left_cmd->cmd_args[2] = NULL;

// 	right_cmd->cmd_args = (char **)malloc(sizeof(char *) * 3);
// 	right_cmd->cmd_args[0] = strdup("grep");
// 	right_cmd->cmd_args[1] = strdup("c");
// 	right_cmd->cmd_args[2] = NULL;

// 	pipe_node->left = left_cmd;
// 	pipe_node->right = right_cmd;
// 	return (pipe_node);
// }
