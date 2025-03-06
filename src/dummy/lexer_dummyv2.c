#include "minishell.h"

static t_token	*new_token(char *val, t_toktype type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = strdup(val);
	token->type = type;
	token->next = NULL;
	return (token);
}

static t_token	*build_ls_grep_pipe(void)
{
	t_token	*head;

	head = new_token("ls", TOK_WORD);
	head->next = new_token("-l", TOK_WORD);
	head->next->next = new_token("|", TOK_PIPE);
	head->next->next->next = new_token("grep", TOK_WORD);
	head->next->next->next->next = new_token("c", TOK_WORD);
	return (head);
}

static t_token	*build_echo_hello(void)
{
	t_token	*head;

	head = new_token("echo", TOK_WORD);
	head->next = new_token("hello", TOK_WORD);
	return (head);
}

static t_token	*build_ls_wc_pipe(void)
{
	t_token	*head;

	head = new_token("ls", TOK_WORD);
	head->next = new_token("|", TOK_PIPE);
	head->next->next = new_token("wc", TOK_WORD);
	head->next->next->next = new_token("-l", TOK_WORD);
	return (head);
}

static t_token	*build_echo_star(void)
{
	t_token	*head;

	head = new_token("echo", TOK_WORD);
	head->next = new_token("*", TOK_WORD);
	return (head);
}

static t_token	*build_cat_error(void)
{
	t_token	*head;

	head = new_token("cat", TOK_WORD);
	head->next = new_token("nonexistentfile", TOK_WORD);
	return (head);
}


t_token	*build_dummy_tokens(int case_num)
{
	if (case_num == 1)
	{
		printf(" Command: ls -l | grep c\n\n");
		printf(" 🔹 Running in Bash:\n------------------------------\n");
		fflush(stdout);
		system("ls -l | grep c");
		printf("\n🔹 Running in Minishell:\n------------------------------\n");
		return (build_ls_grep_pipe());
	}
	if (case_num == 2)
	{
		printf(" Command: echo hello\n\n");
		printf(" 🔹 Running in Bash:\n------------------------------\n");
		fflush(stdout);
		system("echo hello");
		printf("\n🔹 Running in Minishell:\n------------------------------\n");
		return (build_echo_hello());
	}
	if (case_num == 3)
	{
		printf(" Command: ls | wc -l\n\n");
		printf(" 🔹 Running in Bash:\n------------------------------\n");
		fflush(stdout);
		system("ls | wc -l");
		printf("\n🔹 Running in Minishell:\n------------------------------\n");
		return (build_ls_wc_pipe());
	}
	if (case_num == 4)
	{
		printf(" Command: echo *\n\n");
		printf(" 🔹 Running in Bash:\n------------------------------\n");
		fflush(stdout);
		system("echo *");
		printf("\n🔹 Running in Minishell:\n------------------------------\n");
		return (build_echo_star());
	}
	if (case_num == 5)
	{
		printf(" Command: cat nonexistentfile\n\n");
		printf(" 🔹 Running in Bash:\n------------------------------\n");
		fflush(stdout);
		system("cat nonexistentfile");
		printf("\n🔹 Running in Minishell:\n------------------------------\n");
		return (build_cat_error());
	}
	return (NULL);
}
