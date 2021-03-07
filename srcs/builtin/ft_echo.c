/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:41:00 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/07 16:50:09 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include "../../incs/minishell.h"

int	g_exit_status = 0; // test
/*
static void	print_exit_status()
{
	printf("%d", g_exit_status);
}

static int	ft_echo_env(char *obj, char **envs)
{
	int	cnt;
	int	i;

	if (obj[0] == '?')
		print_exit_status();
	cnt = 0;
	while (obj[cnt] && (ft_isalnum(obj[cnt]) || obj[cnt] == '_'))
		cnt++;
	i = 0;
	while (envs[i])
	{
		if (ft_strncmp(obj, envs[i], cnt - 1) == 0 && envs[i][cnt] == '=')
			printf("%s", &envs[i][cnt + 1]);
		i++;
	}
	if (cnt == 0)
		printf("$");
	return (cnt);
}

//환경변수 출력($)를 파싱하지 않은 경우
static void	print_obj(char *obj, char **envs)
{
	int		i;
	char	*temp;

	i = 0;
	temp = obj;
	while (*temp)
	{
		if (*temp == '$')
		{
			*temp = '\0';
			printf("%s", obj);
			temp += ft_echo_env(temp + 1, envs);
			obj = temp + 1;
		}
		temp++;
	}
	printf("%s", obj);
}

static int	check_opt(char *opt)
{
	int i;

	i = 1;
	if (opt[0] != '-')
		return (0);
	while (opt[i])
	{
		if (opt[i++] != 'n')
			return (0);
	}
	return (1);
}

void	ft_echo(char **objs, char **envs)
{
	int opt_n;
	int i;

	opt_n = 0;
	if (objs[0] != NULL)
		opt_n = check_opt(objs[0]);
	i = opt_n;
	while (objs[i])
	{
		if (i > opt_n)
			printf(" ");
		print_obj(objs[i++], envs);
		//if (objs[i][0] == '$')
		//	ft_echo_env(objs[i], envs);
		//printf("%s", objs[i++]);
	}
	if (opt_n == 0)
		printf("\n");
}
*/

static int	check_opt(char *opt)
{
	int	i;
	
	if (opt[0] != '-')
		return (0);
	i = 1;
	while (opt[i])
	{
		if (opt[i++] != 'n')
			return (0);
	}
	return (1);
}

void		ft_echo(char **objs)
{
	int	opt_n;
	int	i;

	opt_n = 0;
	if (objs[0] != NULL)
		opt_n = check_opt(objs[0]);
	i = opt_n;
	while (objs[i])
	{
		if (i > opt_n)
			printf(" ");
		printf("%s", objs[i++]);
	}
	if (opt_n == 0)
		printf("\n");
}
/*
//test main
int	main(int argc, char **argv, char **envp)
{
	int i = 0;
	argv++;
	while(argv[i])
		printf("%s ", argv[i++]);
	printf("\n");
	ft_echo(argv, envp);
}
*/
