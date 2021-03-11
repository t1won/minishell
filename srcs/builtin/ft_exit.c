/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:46:15 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/09 21:21:22 by jaeelee          ###   ########.fr       */
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

void		ft_exit(char **objs)
{
	printf("exit\n");
	if (objs[1] == NULL)
		set_exit_status(0);
	if (!check_obj_isdigit(objs[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", objs[1]);
		set_exit_status(255);
	}
	else if (objs[2] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		set_exit_status(-1);
	}
	else
		set_exit_status(ft_atoi(objs[1]) % 256);
}
