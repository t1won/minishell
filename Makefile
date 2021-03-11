NAME = minishell

SRCS = srcs/main.c \
		srcs/utils/gnl.c \
		srcs/utils/main_utils.c \
		srcs/utils/handling_signals.c \
		srcs/utils/temp.c \
		srcs/read_input/read_line.c	\
		srcs/parser/parser.c \
		srcs/parser/parse_util.c \
		srcs/parser/lexer_1.c \
		srcs/parser/lexer_2.c \
		srcs/parser/token_checker.c \
		srcs/parser/token_conversion_1.c \
		srcs/parser/token_conversion_2.c \
		srcs/error/memory_error.c \
		srcs/error/token_error.c

LIBFT = libft.a

LIBS = -L./libft -lft

HEADER = -I./incs

CFLAG = -Wall -Werror -Wextra

CC = gcc

RM = rm -rf

DEBUG = -g -fsanitize=address

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C ./libft

$(NAME) : $(LIBFT)
	$(CC) $(SRCS) $(LIBS) $(HEADER) $(CFLAG) $(DEBUG) -o $(NAME)

clean :
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean :
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re :
	fclean all



