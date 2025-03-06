/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:33:59 by dmlasko           #+#    #+#             */
/*   Updated: 2025/03/01 15:03:10 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#define TOK_WORD_COLOR	RED
#define TOK_WORD_REPR "<WORD>"


void print_token_repr(int token_type)
{
	char *type_str_color;
	char *type_str_repr;

	if (TOK_WORD == token_type)
		type_str_repr = "<WORD>";
	else if (TOK_AND == token_type)
		type_str_repr = "<AND>";
	else if (TOK_OR == token_type)
		type_str_repr = "<OR>";
	else if (TOK_PIPE == token_type)
		type_str_repr = "<PIPE>";
	else if (TOK_HEREDOC == token_type)
		type_str_repr = "<HEREDOC>";
	else if (TOK_REDIR_IN == token_type)
		type_str_repr = "<REDIR_IN>";
	else if (TOK_APPEND == token_type)
		type_str_repr = "_APPEND>";
	else if (TOK_REDIR_OUT == token_type)
		type_str_repr = "<REDIR_OUT>";
	else
		type_str_repr = "<NA>";
	printf("%s", type_str_repr);
}

void print_separator(void)
{
	int	i;

	i = 0;
	while (i < SEPARATOR_WIDTH)
	{
		ft_putstr_fd(SEPARATOR_CHAR, 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

int is_quote_sign(char c)
{
	return (c == '\'' || c == '\"');
}

int is_allowed_char(char c)
{
	char *allowed_chars;

	allowed_chars = "-@$_\"\'";
	return (ft_strchr(allowed_chars, c) || ft_isalnum(c));
}

int add_token(t_token **tokens, int token_type, char *token_value)
{
	t_token *new_token;
	t_token *current;
	int len;

	if (strcmp(token_value, "") == 0)
		return (0);
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (0);
	new_token->type = token_type;
	new_token->value = token_value;
	new_token->next = NULL;
	if (!*tokens)
		*tokens = new_token;
	else
	{
		current = *tokens;
		while (current->next)
			current = current->next;
		current->next = new_token;
	}
	return (ft_strlen(token_value));
}

int handle_argument(t_token **tokens, char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && is_allowed_char(str[len]))
			len++;
	return (add_token(tokens, TOK_WORD, ft_substr(str, 0, len)));
}

int handle_operator(t_token **tokens, char *str)
{
	if (ft_strncmp(str, AND_CHAR, ft_strlen(AND_CHAR)) == 0)
		return (add_token(tokens, TOK_AND, AND_CHAR));
	else if (ft_strncmp(str, OR_CHAR, ft_strlen(OR_CHAR)) == 0)
		return (add_token(tokens, TOK_OR, OR_CHAR));
	else if (ft_strncmp(str, PIPE_CHAR, ft_strlen(PIPE_CHAR)) == 0)
		return (add_token(tokens, TOK_PIPE, PIPE_CHAR));
	else if (ft_strncmp(str, HEREDOC_CHAR, ft_strlen(HEREDOC_CHAR)) == 0)
		return (add_token(tokens, TOK_HEREDOC, HEREDOC_CHAR));
	else if (ft_strncmp(str, REDIR_IN_CHAR, ft_strlen(REDIR_IN_CHAR)) == 0)
		return (add_token(tokens, TOK_REDIR_IN, REDIR_IN_CHAR));
	else if (ft_strncmp(str, APPEND_CHAR, ft_strlen(APPEND_CHAR)) == 0)
		return (add_token(tokens, TOK_APPEND, APPEND_CHAR));
	else if (ft_strncmp(str, REDIR_OUT_CHAR, ft_strlen(REDIR_OUT_CHAR)) == 0)
		return (add_token(tokens, TOK_REDIR_OUT, REDIR_OUT_CHAR));
	return (1);
}

t_token *tokenize_input(char *str)
{
	t_token *tokens;
	size_t	len;

	tokens = NULL;

	while (*str)
	{
		str += handle_argument(&tokens, str);
		str += handle_operator(&tokens, str);
	}
	return (tokens);
}

void print_out_linked_list(void *list, int print_type)
{
	t_token *current;

	if (!list)
		printf(YELLOW "Token list is empty.\n" RESET);
	current = list;
	printf("[\n");
	while (current)
	{
		printf("\"%s\"", current->value);
		if (print_type)
		{
			printf(":\t");
			print_token_repr(current->type);
		}
		if (current->next != NULL)
		{
			if (print_type)
				printf("\n");
			else
				printf(", ");
		}
		current = current->next;
	}
	printf("\n]\n");

}
int	main(int argc, char **argv, char **envp)
{
	char *user_input;
	t_token *tokens;

	// NOTE: without memset, the input shows some strange artifacts
	ft_memset(user_input, 0, 256);
	// NOTE: while (1) == while (true), the loop works forever until exit / break
	while (1)
	{
		// TODO: move the prompt string to PS1 shell variable
		user_input = readline(PS1_TEXT);
		tokens = tokenize_input(user_input);
		if (DEVELOPER_MODE)
		{
			printf(YELLOW "1. RAW INPUT: " RESET "%s\n", user_input);
			print_separator();
			printf(YELLOW "2. TOKENIZER: \n" RESET);
			print_out_linked_list(tokens, 0);
			print_separator();
			printf(YELLOW "3. LEXER: \n" RESET);
			print_out_linked_list(tokens, 1);
		}
		free(user_input);
	}
	return (0);
}
