#include "minishell.h"

 /**
  * @brief Prints an error message based on the given error code.
  *
  * This function takes an error code of type `t_error` and a context string.
  * If an error has occurred (i.e., `err` is not `ERR_NONE`), it prints a meaningful
  * error message to the standard error output (`stderr`). The function also
  * prints a context string (e.g., a filename or command) if provided.
  *
  * @param err The error code of type `t_error` that represents the error type.
  * @param context A string providing additional context for the error (e.g., a
  * filename or command that caused the error). Can be NULL.
  *
  * @note Uses `perror()` for system-related errors to provide more details.
  */
 void	print_error(t_error err, char *context)
 {
	 if (err == ERR_NONE)
		 return ;

	 // Print optional context
	 if (context)
		 fprintf(stderr, "minishell: %s: ", context);

	 // Print specific error message
	 if (err == ERR_MALLOC)
		 perror("memory allocation failed");
	 else if (err == ERR_SYNTAX)
		 fprintf(stderr, "syntax error\n");
	 else if (err == ERR_CMD_NOT_FOUND)
		 fprintf(stderr, "command not found\n");
	 else if (err == ERR_PERMISSION)
		 perror("permission denied");
	 else if (err == ERR_FILE_NOT_FOUND)
		 perror("no such file or directory");
	 else
		 fprintf(stderr, "unknown error\n");
 }
