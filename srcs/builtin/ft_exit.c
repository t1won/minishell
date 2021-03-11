/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:46:15 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/12 02:09:01 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

extern int	g_exit_status;

static void	set_exit_status(int x)
{
	g_exit_status = x;
	if (x != -1)
		exit(g_exit_status);
	g_exit_status = 1;
}

static int	check_obj_isdigit(char *obj)
{
	int i;

	i = -1;
	while (obj[++i])
	{
		if (!ft_isdigit(obj[i]))
			return (0);
	}
	return (1);
}

void		ft_exit(char **cmd_line)
{
	printf("exit\n");
	if (cmd_line[1] == NULL)
		set_exit_status(0);
	if (!check_obj_isdigit(cmd_line[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd_line[1]);
		set_exit_status(255);
	}
	else if (cmd_line[2] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		set_exit_status(-1);
	}
	else
		set_exit_status(ft_atoi(cmd_line[1]) % 256);
}
