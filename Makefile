NAME = minishell

SRCS = srcs/main.c \
		srcs/utils/gnl.c

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



