

// #include "minishell.h"
// #include <dirent.h> ////Are we allowed to use this?

// int	token_needs_expansion(t_token *token)
// {
// 	if (token->type != TOK_WORD)
// 		return (0);
// 	if (ft_strchr(token->value, '*'))
// 		return (1);
// 	return (0);
// }

// int	match_pattern(char *filename, char *pattern)
// {
// 	if (ft_strcmp(pattern, "*") == 0)
// 		return (1);
// 	return (0); // For now, only handle "*"
// }

// t_list	*get_matching_files(char *pattern)
// {
// 	DIR				*dir;
// 	struct dirent	*entry;
// 	t_list			*matches;

// 	matches = NULL;
// 	dir = opendir(".");
// 	if (!dir)
// 		return (NULL);
// 	while ((entry = readdir(dir)))
// 	{
// 		if (entry->d_name[0] == '.')
// 			continue;
// 		if (match_pattern(entry->d_name, pattern))
// 			ft_lstadd_back(&matches, ft_lstnew(ft_strdup(entry->d_name)));
// 	}
// 	closedir(dir);
// 	return (matches);
// }

// void	free_token(t_token *token)
// {
// 	if (!token)
// 		return ;
// 	free(token->value);
// 	free(token);
// }

// void	expand_token(t_token **token_ptr)
// {
// 	t_token	*token = *token_ptr;
// 	t_list	*matches;
// 	t_list	*cur;
// 	t_token	*prev = NULL;
// 	t_token	*next = token->next;

// 	matches = get_matching_files(token->value);
// 	if (!matches)
// 		return ;
// 	cur = matches;
// 	while (cur)
// 	{
// 		t_token *new_tok = malloc(sizeof(t_token));
// 		if (!new_tok)
// 			exit(EXIT_FAILURE); // Handle malloc fail
// 		new_tok->value = ft_strdup(cur->content);
// 		new_tok->type = TOK_WORD;
// 		new_tok->next = NULL;
// 		if (prev)
// 			prev->next = new_tok;
// 		else
// 			*token_ptr = new_tok;
// 		prev = new_tok;
// 		cur = cur->next;
// 	}
// 	if (prev)
// 		prev->next = next;
// 	free_token(token); // Original token is replaced
// 	ft_lstclear(&matches, free);
// }
