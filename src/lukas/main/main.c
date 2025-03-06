#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

static int	get_test_case(int argc, char **argv)
{
	int	case_num;

	if (argc < 2)
		return (1); // Default to case 1 if no argument provided
	case_num = ft_atoi(argv[1]);
	if (case_num < 1 || case_num > 5)
	{
		printf("Invalid test case: %d (choose 1 to 5)\n", case_num);
		exit(EXIT_FAILURE);
	}
	return (case_num);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	int		test_case;

	test_case = get_test_case(argc, argv);
	printf("\n=== Running Test Case %d ===\n", test_case);

	shell.env = init_env(envp);
	shell.tokens = build_dummy_tokens(test_case);
	shell.ast = parse_tokens(shell.tokens);
	shell.last_exit_code = 0;

	exec_ast(shell);

	free_ast(shell.ast);
	free_tokens(shell.tokens);
	free_env(shell.env); // Don’t forget to free env list
	return (0);
}
