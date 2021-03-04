/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:14 by tseo              #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2021/03/02 12:13:54 by tseo             ###   ########.fr       */
=======
/*   Updated: 2021/03/02 13:10:06 by tseo             ###   ########.fr       */
>>>>>>> tseo
=======
/*   Updated: 2021/03/03 19:43:23 by tseo             ###   ########.fr       */
>>>>>>> 08a6c67e7b3f75e1ce884c0b9acb2bbc0bab05c6
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

<<<<<<< HEAD
<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
=======
# include <stdio.h>
# include <stdlib.h>
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../libft/libft.h"
>>>>>>> 08a6c67e7b3f75e1ce884c0b9acb2bbc0bab05c6

#define STDIN 0
#define STDOUT 1
#define MAXSIZE 1024

#define COLOR_BR_BLUE "\033[34;1m"
#define COLOR_WHITE "\033[37m"
#define COLOR_CYAN "\033[36m"
#define END_COLOR "\033[0m"

#define MAX_FD 1024
#define GNL_BUFFER_SIZE 25

typedef struct s_cmd
{
	char *cmd;			// command
	char *opt;			// option
	char **obj;			// object
	char **redir;		// redirection
	char **path;		// path
	char pipe;			// pipe or redirection
	int fd_in;			// fd in?
	struct s_cmd *next; // linked list
} t_cmd;

typedef struct s_env
{
	char *key;
	char *value;
} t_env;

extern char	**g_envp;


/*
** utils/gnl
*/
char			*ft_strappend(char *s1, char *s2);
int				get_next_line(int fd, char **line);

/*
** utils/main_utils
*/
void	print_prompt(void);
void	copy_environment_variables(char **envs);

/*
** utils/handling_signals.c
*/
void	handle_main_signals(void);
void	main_signal_handler(int signo);
void	child_signal_hanlder(int signo);

<<<<<<< HEAD
# define MAX_FD 1024
# define GNL_BUFFER_SIZE 25
>>>>>>> tseo
=======
>>>>>>> 08a6c67e7b3f75e1ce884c0b9acb2bbc0bab05c6

#endif
