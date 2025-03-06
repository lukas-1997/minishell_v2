// /* lexer_dummy.c */

// #include "minishell.h"

// static t_token	*new_token(char *val, t_toktype type)
// {
// 	t_token *t = malloc(sizeof(t_token));
// 	if (!t)
// 		return (NULL);
// 	t->value = strdup(val);
// 	t->type = type;
// 	t->next = NULL;
// 	return (t);
// }

// t_token	*build_dummy_tokens(void)
// {
// 	t_token *head = new_token("ls", TOK_WORD);
// 	t_token *tmp = head;

// 	tmp->next = new_token("-l", TOK_WORD);
// 	tmp = tmp->next;
// 	tmp->next = new_token("|", TOK_PIPE);
// 	tmp = tmp->next;
// 	tmp->next = new_token("grep", TOK_WORD);
// 	tmp = tmp->next;
// 	tmp->next = new_token("c", TOK_WORD);
// 	return (head);
// }
