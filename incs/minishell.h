/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:14 by tseo              #+#    #+#             */
/*   Updated: 2021/03/11 13:21:48 by tseo             ###   ########.fr       */
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

extern int	g_exit_status;
extern char	**g_envs;
extern char *builtin_str[];
extern int (*builtin_func[]) (char **);


/*
** utils/temp => need to be deleted
*/
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int ft_launch(char **args);
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
char	*get_token(char *line, int token_size);
int		skip_separator_spaces(char *line, int i);
int		skip_separator(char *line, int i);
int		check_backslash(char *line, int *i, char quote);
int		check_and_jmp_quotes(char *line, int i);
int		count_tokens(char *line);

/*
** token checker
*/
int		check_tokens(char **tokens);

/*
** parse util
*/
int		is_separtor(char *sep, char c);
int		is_redirection(char *token);
int		is_pipe(char *token);
int		is_semicolon(char *token);
char	*get_envs_value(char *key);

/*
** token conversion
*/
char *convert_sq_token(char *token);
char	*convert_env_token(char *token);
char	*convert_dq_token(char *token);

/*
** error
*/
void	memory_alloc_error(void);
int		syntax_error(char *token);
int		no_command_error(char *cmd);
int		too_many_args_error(char *cmd);

#endif
