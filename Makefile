include config.mk

# Project Name
NAME = minishell

CC = cc

INC = ./inc

CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -Wall -Werror -Wextra -g -D DEBUG=1

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)**/*.c)
OBJ = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

# libraries
LIBDIRS = ./lib/

LIBFT_DIR = $(LIBDIRS)libft/
LIBFT = $(LIBFT_DIR)libft.a

.DEFAULT_GOAL := all

all: $(LIBFT) $(NAME) $(HEADER_FILE)

# $(NAME): $(OBJ)
# 	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
# 	@echo "\n$(GREEN)$(NAME) got successfully compiled.$(RST)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIBFT) -L$(LIBFT_DIR) -lft
	@echo "\n$(GREEN)$(NAME) got successfully compiled.$(RST)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "$(GREEN)%%%%$(RST)\c"


clean:
	@rm -f $(OBJ_DIR)**/*.o
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)clean complete\n$(RST)\c"

fclean: clean
	@rm -f $(NAME) $(HEADER_FILE)
	@echo "$(YELLOW)fclean complete\n$(RST)\c"
	@rm -rf ./logs/

libft:
	$(MAKE) -C $(LIBFT_DIR)

re: fclean all

PHONY: all clean fclean all libft