/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:27:39 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/12 02:06:32 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

extern char **g_envs;

void	ft_env(char **cmd_line)
{
	int	i;

	(void)cmd_line;
	i = 0;
	while (g_envs[i])
		printf("%s\n", g_envs[i++]);
}
