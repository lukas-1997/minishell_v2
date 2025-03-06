// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parser.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+    */
// /*   By: yourlogin <yourlogin@student.42.fr>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/28 11:00:00 by yourlogin         #+#    #+#             */
// /*   Updated: 2025/02/28 11:00:00 by yourlogin        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// /*
// ** new_ast_node:
// ** Allocates and initializes a new AST node.
// */
// static t_ast	*new_ast_node(t_asttype type)
// {
// 	t_ast	*node;

// 	node = malloc(sizeof(t_ast));
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

// /*
// ** parse_tokens:
// ** Entry point — parses entire command line into AST.
// */
// static t_ast	*parse_tokens(t_token *tokens)
// {
// 	return (parse_sequence(&tokens));
// }

// /*
// ** parse_sequence:
// ** Handles sequences split by semicolons (;).
// */
// static t_ast	*parse_sequence(t_token **tokens)
// {
// 	t_ast	*left;
// 	t_ast	*node;

// 	left = parse_logical(tokens);
// 	while (*tokens && (*tokens)->type == TOK_SEMICOLON)
// 	{
// 		node = new_ast_node(AST_SEQ);
// 		*tokens = (*tokens)->next;
// 		node->left = left;
// 		node->right = parse_logical(tokens);
// 		left = node;
// 	}
// 	return (left);
// }

// /*
// ** parse_logical:
// ** Handles logical operators (&&, ||).
// */
// static t_ast	*parse_logical(t_token **tokens)
// {
// 	t_ast	*left;
// 	t_ast	*node;

// 	left = parse_pipeline(tokens);
// 	while (*tokens && ((*tokens)->type == TOK_AND || (*tokens)->type == TOK_OR))
// 	{
// 		node = new_ast_node((*tokens)->type == TOK_AND ? AST_AND : AST_OR);
// 		*tokens = (*tokens)->next;
// 		node->left = left;
// 		node->right = parse_pipeline(tokens);
// 		left = node;
// 	}
// 	return (left);
// }

// /*
// ** parse_pipeline:
// ** Handles pipes (|).
// */
// static t_ast	*parse_pipeline(t_token **tokens)
// {
// 	t_ast	*left;
// 	t_ast	*node;

// 	left = parse_command(tokens);
// 	while (*tokens && (*tokens)->type == TOK_PIPE)
// 	{
// 		node = new_ast_node(AST_PIPE);
// 		*tokens = (*tokens)->next;
// 		node->left = left;
// 		node->right = parse_command(tokens);
// 		left = node;
// 	}
// 	return (left);
// }

// /*
// ** parse_command:
// ** Handles single commands (with redirections).
// */
// static t_ast	*parse_command(t_token **tokens)
// {
// 	t_ast	*cmd;

// 	if (*tokens && (*tokens)->type == TOK_LPAREN)
// 		return (parse_subshell(tokens));
// 	cmd = new_ast_node(AST_CMD);
// 	cmd->cmd_args = tokens_to_args(tokens);
// 	while (*tokens && is_redirection((*tokens)->type))
// 		parse_redirection(cmd, tokens);
// 	return (cmd);
// }

// /*
// ** parse_subshell:
// ** Handles subshells ((command)).
// */
// static t_ast	*parse_subshell(t_token **tokens)
// {
// 	t_ast	*subshell;

// 	*tokens = (*tokens)->next;
// 	subshell = new_ast_node(AST_SUBSHELL);
// 	subshell->left = parse_sequence(tokens);
// 	if (!(*tokens) || (*tokens)->type != TOK_RPAREN)
// 	{
// 		ft_putstr_fd("minishell: syntax error: unmatched parenthesis\n", 2);
// 		free_ast(subshell);
// 		return (NULL);
// 	}
// 	*tokens = (*tokens)->next;
// 	return (subshell);
// }

// /*
// ** parse_redirection:
// ** Handles >, <, >>, <<.
// */
// static void	parse_redirection(t_ast *cmd, t_token **tokens)
// {
// 	t_ast	*redir;

// 	redir = new_ast_node(AST_REDIR);
// 	if ((*tokens)->type == TOK_REDIR_OUT)
// 		redir->append = 0;
// 	else if ((*tokens)->type == TOK_APPEND)
// 		redir->append = 1;
// 	else
// 		redir->append = 0;
// 	*tokens = (*tokens)->next;
// 	redir->redir_file = strdup((*tokens)->value);
// 	*tokens = (*tokens)->next;
// 	redir->left = cmd;
// 	*cmd = *redir;
// 	free(redir);
// }

// /*
// ** tokens_to_args:
// ** Converts a sequence of TOK_WORD into argv array.
// */
// char	**tokens_to_args(t_token **tokens)
// {
// 	t_token	*cur = *tokens;
// 	char	**args;
// 	int		count = 0;

// 	while (cur && cur->type == TOK_WORD)
// 	{
// 		count++;
// 		cur = cur->next;
// 	}
// 	args = malloc(sizeof(char *) * (count + 1));
// 	count = 0;
// 	while (*tokens && (*tokens)->type == TOK_WORD)
// 	{
// 		args[count++] = strdup((*tokens)->value);
// 		*tokens = (*tokens)->next;
// 	}
// 	args[count] = NULL;
// 	return (args);
// }

// /*
// ** is_redirection:
// ** Checks if token is a redirection.
// */
// int	is_redirection(t_toktype type)
// {
// 	return (type == TOK_REDIR_OUT || type == TOK_REDIR_IN ||
// 			type == TOK_APPEND || type == TOK_HEREDOC);
// }
