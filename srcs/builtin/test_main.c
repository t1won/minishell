/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:24:46 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/10 23:06:59 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	**g_envs;
int		g_exit_status = 0;

void	ft_echo(char **objs, char **envs);
int		ft_pwd();
void	ft_cd(char *obj);
void	ft_env();
void	ft_exit(char **objs);
void	ft_export(char **cmd_line);

int		ft_arrsize(char **arr)
{
	int	cnt;
	
	cnt = 0;
	while (arr[cnt])
		cnt++;
	return (cnt);
}

void	get_envs(char **envp)
{
	int i;
	int cnt;

	cnt = ft_arrsize(envp);
	i = -1;
	if( !(g_envs = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return ;
	while (++i < cnt)
		g_envs[i] = ft_strdup(envp[i]);
	g_envs[i] = NULL;
}

int		main(int argc, char **argv, char **envp)
{
	printf("argv[1] = %s\n", argv[1]);
	get_envs(envp);
	/*
	//test pwd
	ft_pwd();
	ft_env();
	//test cd
	ft_cd(argv[1]);
	ft_pwd();

	//test env
	printf("\n\nchagne env : \n");
	ft_env();
	*/
	//test exit
//	ft_exit(argv);
//	printf("g_exit_status : %d\n", g_exit_status);

	ft_export(argv);
	return (0);
}
