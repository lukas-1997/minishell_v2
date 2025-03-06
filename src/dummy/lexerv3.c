// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   lexer_dummy.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+    */
// /*   By: yourlogin <yourlogin@student.42berlin.de>   +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/28 10:00:00 by yourlogin         #+#    #+#             */
// /*   Updated: 2025/02/28 10:00:00 by yourlogin        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// /*
// ** new_token:
// ** Allocates and initializes a new token.
// */
// static t_token	*new_token(char *val, t_toktype type)
// {
// 	t_token	*token;

// 	token = malloc(sizeof(t_token));
// 	if (!token)
// 		return (NULL);
// 	token->value = strdup(val);
// 	token->type = type;
// 	token->next = NULL;
// 	return (token);
// }

// /* All the command builders (same ones we discussed) */

// static t_token	*build_ls_grep_pipe(void)
// {
// 	printf("Command: ls -l | grep c\n");
// 	return (new_token("ls", TOK_WORD))->next =
// 		new_token("-l", TOK_WORD)->next =
// 		new_token("|", TOK_PIPE)->next =
// 		new_token("grep", TOK_WORD)->next =
// 		new_token("c", TOK_WORD);
// }

// static t_token	*build_echo_hello(void)
// {
// 	printf("Command: echo hello\n");
// 	return (new_token("echo", TOK_WORD))->next =
// 		new_token("hello", TOK_WORD);
// }

// static t_token	*build_ls_wc_pipe(void)
// {
// 	printf("Command: ls | wc -l\n");
// 	return (new_token("ls", TOK_WORD))->next =
// 		new_token("|", TOK_PIPE)->next =
// 		new_token("wc", TOK_WORD)->next =
// 		new_token("-l", TOK_WORD);
// }

// static t_token	*build_echo_star(void)
// {
// 	printf("Command: echo *\n");
// 	return (new_token("echo", TOK_WORD))->next =
// 		new_token("*", TOK_WORD);
// }

// static t_token	*build_cat_error(void)
// {
// 	printf("Command: cat nonexistentfile\n");
// 	return (new_token("cat", TOK_WORD))->next =
// 		new_token("nonexistentfile", TOK_WORD);
// }

// static t_token	*build_ls_grep_redir(void)
// {
// 	printf("Command: ls -l | grep minishell > result.txt\n");
// 	return (new_token("ls", TOK_WORD))->next =
// 		new_token("-l", TOK_WORD)->next =
// 		new_token("|", TOK_PIPE)->next =
// 		new_token("grep", TOK_WORD)->next =
// 		new_token("minishell", TOK_WORD)->next =
// 		new_token(">", TOK_REDIR_OUT)->next =
// 		new_token("result.txt", TOK_WORD);
// }

// static t_token	*build_cat_and_or(void)
// {
// 	printf("Command: cat file.txt && echo \"done\" || echo \"failed\"\n");
// 	return (new_token("cat", TOK_WORD))->next =
// 		new_token("file.txt", TOK_WORD)->next =
// 		new_token("&&", TOK_AND)->next =
// 		new_token("echo", TOK_WORD)->next =
// 		new_token("done", TOK_WORD)->next =
// 		new_token("||", TOK_OR)->next =
// 		new_token("echo", TOK_WORD)->next =
// 		new_token("failed", TOK_WORD);
// }

// static t_token	*build_subshell_and(void)
// {
// 	printf("Command: (ls -l | grep .c) && echo \"Found\"\n");
// 	return (new_token("(", TOK_LPAREN))->next =
// 		new_token("ls", TOK_WORD)->next =
// 		new_token("-l", TOK_WORD)->next =
// 		new_token("|", TOK_PIPE)->next =
// 		new_token("grep", TOK_WORD)->next =
// 		new_token(".c", TOK_WORD)->next =
// 		new_token(")", TOK_RPAREN)->next =
// 		new_token("&&", TOK_AND)->next =
// 		new_token("echo", TOK_WORD)->next =
// 		new_token("Found", TOK_WORD);
// }

// static t_token	*build_redir_and_cat(void)
// {
// 	printf("Command: echo \"Start\" > log.txt && cat log.txt\n");
// 	return (new_token("echo", TOK_WORD))->next =
// 		new_token("Start", TOK_WORD)->next =
// 		new_token(">", TOK_REDIR_OUT)->next =
// 		new_token("log.txt", TOK_WORD)->next =
// 		new_token("&&", TOK_AND)->next =
// 		new_token("cat", TOK_WORD)->next =
// 		new_token("log.txt", TOK_WORD);
// }

// static t_token	*build_cat_grep_redir(void)
// {
// 	printf("Command: cat < input.txt | grep foo > output.txt\n");
// 	return (new_token("cat", TOK_WORD))->next =
// 		new_token("<", TOK_REDIR_IN)->next =
// 		new_token("input.txt", TOK_WORD)->next =
// 		new_token("|", TOK_PIPE)->next =
// 		new_token("grep", TOK_WORD)->next =
// 		new_token("foo", TOK_WORD)->next =
// 		new_token(">", TOK_REDIR_OUT)->next =
// 		new_token("output.txt", TOK_WORD);
// }

// static t_token	*build_seq_and_touch(void)
// {
// 	printf("Command: mkdir testdir ; cd testdir && touch file.txt\n");
// 	return (new_token("mkdir", TOK_WORD))->next =
// 		new_token("testdir", TOK_WORD)->next =
// 		new_token(";", TOK_SEMICOLON)->next =
// 		new_token("cd", TOK_WORD)->next =
// 		new_token("testdir", TOK_WORD)->next =
// 		new_token("&&", TOK_AND)->next =
// 		new_token("touch", TOK_WORD)->next =
// 		new_token("file.txt", TOK_WORD);
// }

// /*
// ** build_dummy_tokens:
// ** Entry point to select the correct test case.
// */
// t_token	*build_dummy_tokens(int case_num)
// {
// 	if (case_num == 1)
// 		return (build_ls_grep_pipe());
// 	if (case_num == 2)
// 		return (build_echo_hello());
// 	if (case_num == 3)
// 		return (build_ls_wc_pipe());
// 	if (case_num == 4)
// 		return (build_echo_star());
// 	if (case_num == 5)
// 		return (build_cat_error());
// 	if (case_num == 6)
// 		return (build_ls_grep_redir());
// 	if (case_num == 7)
// 		return (build_cat_and_or());
// 	if (case_num == 8)
// 		return (build_subshell_and());
// 	if (case_num == 9)
// 		return (build_redir_and_cat());
// 	if (case_num == 10)
// 		return (build_cat_grep_redir());
// 	if (case_num == 11)
// 		return (build_seq_and_touch());
// 	printf("Invalid test case number: %d\n", case_num);
// 	return (NULL);
// }
