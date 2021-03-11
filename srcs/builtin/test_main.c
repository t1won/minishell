/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:24:46 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/12 01:42:38 by jaeelee          ###   ########.fr       */
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
void	ft_unset(char **cmd_line);

int		ft_arrsize(char **arr)
{
	int	cnt;
	
	cnt = 0;
	while (arr[cnt])
		cnt++;
	return (cnt);
}
/*
void	get_envs(char **envp)
{
	int cnt;

	cnt = ft_arrsize(envp);
	if (!(g_envs = (char **)malloc(sizeof(char *) * (cnt + 1))))
		exit(EXIT_FAILURE);
	cnt = -1;
	while (envp[++cnt])
		g_envs[cnt] = ft_strdup(envp[cnt]);
	g_envs[cnt] = NULL;
}
*/
char	**get_envs(char **envs, int cnt)
{
	int i;
	char **temp;

	if (!(temp = (char **)malloc(sizeof(char *) * (cnt + 1))))
		exit(EXIT_FAILURE);
	i = -1;
	while (envs[++i])
		temp[i] = ft_strdup(envs[i]);
	temp[i] = NULL;
	return (temp);
}

int		main(int argc, char **argv, char **envp)
{
	printf("argv[1] = %s\n", argv[1]);
	g_envs = get_envs(envp, ft_arrsize(envp));
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
	char *temp[2];
	temp[0] = "export";
	temp[1] = NULL;
	ft_export(temp);
	ft_unset(argv);
	printf("before\n");
	ft_export(temp);
	while (1)
	{}
	return (0);
}
