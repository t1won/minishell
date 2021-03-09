/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:14 by tseo              #+#    #+#             */
/*   Updated: 2021/03/09 09:36:09 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../libft/libft.h"
#include "const.h"
#include "data_types.h"

extern char	**g_envp;
extern char *builtin_str[];
extern int (*builtin_func[]) (char **);


/*
** utils/temp => need to be deleted
*/
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int ft_launch(char **args);
char **ft_split_line(char *line);
int ft_execute(char **args);
int lsh_num_builtins();

/*
** read_input
*/
int		get_input_line(char **line);

/*
** utils/ft_charset_split
*/
char	**ft_charset_split(char *str, char *charset);

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

/*
** parser
*/
char	**parse_input_line(char *line);

/*
** lexer
*/
void	lexing(char *cmd_line, char **tokens, int token_num);

/*
** parse util
*/
int		is_separtor(char *sep, char c);

/*
** error
*/
void	memory_alloc_error(void);

#endif
