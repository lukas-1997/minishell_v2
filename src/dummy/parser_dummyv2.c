
#include "minishell.h"

static t_ast	*new_ast_node(t_asttype type)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = type;
	node->cmd_args = NULL;
	node->redir_file = NULL;
	node->append = 0;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static t_ast	*parse_simple_cmd(t_token *tokens)
{
	t_ast	*cmd_node;
	t_token	*current;
	int		arg_count;

	cmd_node = new_ast_node(AST_CMD);
	arg_count = 0;
	current = tokens;
	while (current && current->type == TOK_WORD)
	{
		arg_count++;
		current = current->next;
	}
	cmd_node->cmd_args = malloc(sizeof(char *) * (arg_count + 1));
	if (!cmd_node->cmd_args)
		return (NULL);
	current = tokens;
	arg_count = 0;
	while (current && current->type == TOK_WORD)
	{
		cmd_node->cmd_args[arg_count++] = strdup(current->value);
		current = current->next;
	}
	cmd_node->cmd_args[arg_count] = NULL;
	return (cmd_node);
}

t_ast	*parse_tokens(t_token *tokens)
{
	t_ast	*root;

	if (!tokens)
		return (NULL);
	if (tokens->next && tokens->next->type == TOK_PIPE)
	{
		root = new_ast_node(AST_PIPE);
		root->left = parse_simple_cmd(tokens);
		root->right = parse_simple_cmd(tokens->next->next);
	}
	else
		root = parse_simple_cmd(tokens);
	return (root);
}
