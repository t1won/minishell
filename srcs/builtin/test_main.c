/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:24:46 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/07 19:15:45 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	**g_envs;

void	ft_echo(char **objs, char **envs);
int		ft_pwd();
void	ft_cd(char *obj);
void	ft_env();

int		get_envs_num(char **envp)
{
	int cnt;

	cnt = 0;
	while (envp[cnt])
		cnt++;
	return (cnt);
}

void	get_envs(char **envp)
{
	int i;
	int cnt;

	cnt = get_envs_num(envp);
	i = -1;
	g_envs = (char **)malloc(sizeof(char *) * cnt);
	while (++i < cnt)
		g_envs[i] = ft_strdup(envp[i]);
	g_envs[i] = NULL;
}

int		main(int argc, char **argv, char **envp)
{
	printf("argv[1] = %s\n", argv[1]);
	get_envs(envp);
	//test pwd
	ft_pwd();
	ft_env();
	//test cd
	ft_cd(argv[1]);
	ft_pwd();

	printf("\n\nchagne env : \n");
	ft_env();
	return (0);
}
