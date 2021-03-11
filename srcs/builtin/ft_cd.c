/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:02:25 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/12 02:07:13 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

#define PATH_MAX 1024

extern char **g_envs;

static void	set_pwd(void)
{
	char	*old_pwd;
	char	pwd[PATH_MAX];
	int		i;

	i = 0;
	while (g_envs[i])
	{
		if (ft_strncmp(g_envs[i], "PWD=", 4) == 0)
			old_pwd = &g_envs[i][5];
		i++;
	}
	getcwd(pwd, PATH_MAX);
	i = 0;
	while (g_envs[i])
	{
		if (ft_strncmp(g_envs[i], "OLDPWD=", 7) == 0)
			g_envs[i] = ft_strjoin("OLDPWD=", old_pwd); //free 필요?
		if (ft_strncmp(g_envs[i], "PWD=", 4) == 0)
			g_envs[i] = ft_strjoin("PWD=", pwd);
		i++;
	}
}

void		ft_cd(char **cmd_line)
{
	if (chdir(cmd_line[1]) == -1)
		printf("working directory change error: %s\n", strerror(errno));
	set_pwd();
}
