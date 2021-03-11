/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:33:33 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/11 00:44:14 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int		ft_arrsize(char **arr);
void	get_envs(char **envp);
char	*search_env(char *key);

extern char	**g_envs;

t_env		*get_key_value(int cnt)
{
	t_env	*env;
	int		i;
	int		size_key;
	int		size_value;

	env = (t_env *)malloc(sizeof(t_env) * (cnt + 1));
	i = -1;
	while (g_envs[++i])
	{
		size_key = ft_strchr(g_envs[i], '=') - g_envs[i] + 1;
		size_value = ft_strlen(g_envs[i]) - size_key + 1;
		env[i].key = (char *)malloc(sizeof(char) * size_key);
		env[i].value = (char *)malloc(sizeof(char) * size_value);
		ft_strlcpy(env[i].key, g_envs[i], size_key);
		ft_strlcpy(env[i].value, &g_envs[i][size_key], size_value);
	}
	if (search_env("OLDPWD") == NULL)
	{
		env[i].key = "OLDPWD";
		env[i++].value = NULL;
	}
	env[i].key = NULL;
	return (env);
}

t_env		*sort_env(t_env *env)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (env[++i].key)
	{
		j = i;
		while (env[++j].key)
		{
			if (ft_strncmp(
						env[i].key, env[j].key, ft_strlen(env[i].key) + 1) > 0)
			{
				temp = env[i].key;
				env[i].key = env[j].key;
				env[j].key = temp;
				temp = env[i].value;
				env[i].value = env[j].value;
				env[j].value = temp;
			}
		}
	}
	return (env);
}

char		*search_env(char *key)
{
	int	i;

	i = -1;
	while (g_envs[++i])
	{
		if (ft_strncmp(key, g_envs[i], ft_strlen(key)) == 0 &&
				g_envs[i][ft_strlen(key)] == '=')
			return (&g_envs[i][ft_strlen(key) + 1]);
	}
	return (NULL);
}

/*
** export명령어에 인자가 없는 경우
** 1. key를 정렬- (아스키코드 작은값부터)
** 2. declare -x key="value" 형태로 출력
*/

static void	print_export(void)
{
	t_env	*env;
	int		i;
	int		cnt;

	cnt = ft_arrsize(g_envs);
	if (search_env("OLDPWD") == NULL)
		cnt++;
	env = sort_env(get_key_value(cnt));
	i = -1;
	while (env[++i].key)
	{
		printf("declare -x %s", env[i].key);
		if (env[i].value != NULL)
			printf("=\"%s\"", env[i].value);
		printf("\n");
	}
	printf("%d %d\n", i, cnt);
}

void		ft_export(char **cmd_line)
{
	char	**temp;
	int		cnt;

	if (ft_arrsize(cmd_line) == 1)
		print_export();

	cnt = ft_arrsize(g_envs) + ft_arrsize(cmd_line);
	if (!(temp = (char **)malloc(sizeof(char *) * cnt)))
		return ; //malloc failed error
}
