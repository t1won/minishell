/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:33:33 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/12 02:14:02 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int		ft_arrsize(char **arr);
char	**get_envs(char **envs, int cnt);
char	*search_env(char *key);
char	*get_key(char *obj);
void	*free_arr_env(t_env *env);
t_env	*sort_env(t_env *env);
void	free_double_arr(char **arr);

extern char	**g_envs;
extern int	g_exit_status;

static t_env	*get_key_value(int cnt)
{
	t_env	*env;
	int		i;

	env = (t_env *)malloc(sizeof(t_env) * (cnt + 1));
	i = -1;
	while (g_envs[++i])
	{
		env[i].key = get_key(g_envs[i]);
		env[i].value = search_env(env[i].key);
	}
	if (search_env("OLDPWD") == NULL)
	{
		env[i].key = ft_strdup("OLDPWD");
		env[i++].value = NULL;
	}
	env[i].key = NULL;
	return (env);
}

static void		print_export(void)
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
	free_arr_env(env);
}

static void		add_env(char **envs, char *key, char *new)
{
	char	*value;
	int		i;

	i = -1;
	while (envs[++i])
	{
		if (ft_strncmp(key, envs[i], ft_strlen(key)) == 0 &&
				envs[i][ft_strlen(key)] == '=')
		{
			free(envs[i]);
			break ;
		}
	}
	envs[i] = ft_strdup(new);
	if (i == ft_arrsize(envs))
		envs[++i] = NULL;
	free(key);
}

void			ft_export(char **cmd_line)
{
	char	**temp;
	char	*key;
	int		cnt;
	int		i;

	if (ft_arrsize(cmd_line) == 1)
		print_export();
	cnt = ft_arrsize(g_envs) + ft_arrsize(cmd_line);
	temp = get_envs(g_envs, cnt - 1);
	i = 0;
	while (cmd_line[++i])
	{
		if ((key = get_key(cmd_line[i])) == NULL)
		{
			printf("minishell: export: '%s': not a valid idetifier\n",
					cmd_line[i]);
			g_exit_status = 1;
		}
		else
			add_env(temp, key, cmd_line[i]);
	}
	free_double_arr(g_envs);
	g_envs = temp;
}
