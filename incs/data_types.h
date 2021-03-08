/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:48:32 by tseo              #+#    #+#             */
/*   Updated: 2021/03/07 08:57:40 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPES_H
# define DATA_TYPES_H

typedef struct s_cmd
{
	char *cmd;			// command
	char **argv;			// object

	char **redir;		// redirection
	char **path;		// path
	char pipe;			// pipe or redirection
	int fds[2];

	struct s_cmd *prev;
	struct s_cmd *next;
} t_cmd;

#endif
