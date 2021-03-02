/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:14 by tseo              #+#    #+#             */
/*   Updated: 2021/03/02 14:50:36 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define MAXSIZE 1024

# define COLOR_BR_BLUE	"\033[34;1m"
# define COLOR_WHITE	"\033[37m"
# define COLOR_CYAN		"\033[36m"
# define END_COLOR		"\033[0m"


# define MAX_FD 1024
# define GNL_BUFFER_SIZE 25

typedef struct		s_cmd
{
	char			*cmd; // command
	char			*opt; // option
	char			**obj; // object
	char			**redir; // redirection
	char			**path; // path
	char			pipe; // pipe or redirection
	int				fd_in; // fd in?
	struct s_cmd	*next; // linked list
}					t_cmd;

typedef struct		s_env
{
	char *key;
	char *value;
}					t_env;



/*
** main_utils
*/
int				get_next_line(int fd, char **line);


#endif
