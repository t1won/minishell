/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_conversion_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:43:53 by tseo              #+#    #+#             */
/*   Updated: 2021/03/12 21:02:37 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/*
- 환경변수
    - $HOME
    - $?
    - 존재하지 않는경우
- `\\` → `\`
- `\"` → `"`
*/

// 백슬래시 뒤에 있는 dq는 지우면 안되는데 맨 뒤에 있는 백슬래시는 지워도 된다.
char	*handling_dq_doublequotes(char *token)
{
	int i;
	int j;
	int size;
	char *converted_token;

	i = 0;
	size = 0;
	while (token[i])
	{
		if (token[i] != '\"' || (i > 0 && token[i] == '\"' && token[i - 1] == '\\' && token[i + 1]))
			size++;
		i++;
	}
	if (!(converted_token = (char *)malloc(sizeof(char) * (size + 1))))
		memory_alloc_error();
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] != '\"' || (i > 0 && token[i] == '\"' && token[i - 1] == '\\' && token[i + 1]))
		{
			converted_token[j] = token[i];
			j++;
		}
		i++;
	}
	converted_token[size] = 0;

	free(token);
	return (converted_token);
}

char	*handling_dq_backslash(char *token)
{
	int i;
	int j;
	int size;
	char *converted_token;
	int len;

	i = 0;
	size = 0;
	len = ft_strlen(token);
	while (token[i])
	{
		if (token[i] == '\\' && token[i + 1] == '\\')
		{
			i += 2;
			size++;
			continue;
		}
		if (i != len - 2 && token[i] == '\\' && token[i + 1] == '\"') // 맨 뒤
		{
			i += 2;
			size++;
			continue;
		}
		size++;
		i++;
	}
	if (!(converted_token = (char *)malloc(sizeof(char) * (size + 1))))
		memory_alloc_error();
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] == '\\' && token[i + 1] == '\\')
		{
			converted_token[j] = token[i];
			i += 2;
			j++;
			continue;
		}
		if (i != len - 2 && token[i] == '\\' && token[i + 1] == '\"') // 맨 뒤
		{
			converted_token[j] = token[i + 1];
			i += 2;
			j++;
			continue;
		}
		converted_token[j] = token[i];
		j++;
		i++;
	}
	converted_token[size] = 0;
	// printf("conveted: %s\n", converted_token);
	free(token);
	// printf("SIZE: %d\n", size);
	return (converted_token);
}

char	*handling_dq_env(char *token)
{
	int i;
	int env_key_len;
	char *converted_token = 0;
	char *key;
	int	dollor_count = 0;

	i = 0;
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] != ' ')
			dollor_count++;
		i++;
	}
	printf("DOLLOR COUNT: %d\n", dollor_count);

	if (dollor_count > 0)
	{
	char **dq_envs;
	if (!(dq_envs = (char **)malloc(sizeof(char *) * (dollor_count + 1))))
		memory_alloc_error();
	dq_envs[dollor_count] = 0;

	i = 0;
	int j = 0;
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] != ' ')
		{
			env_key_len = 0;
			while (token[i + env_key_len])
			{
				if (token[i + env_key_len] == ' ')
					break ;
				if (token[i + env_key_len + 1] == '$')
				{
					env_key_len++;
					break ;
				}
				env_key_len++;
			}
			// printf("KEY LEN = %d\n", env_key_len);
			key = ft_substr(&token[i], 0, env_key_len);
			// printf("KEY = %s\n", key);
			dq_envs[j] = ft_strdup(key);
			j++;
			free(key);
		}
		i++;
	}
	for (int i = 0; dq_envs[i]; i++)
		printf("KEYS[%d]: %s\n", i, dq_envs[i]);
	i = 0;
	while (i < dollor_count)
	{
		dq_envs[i] = convert_env_token(dq_envs[i]);
		i++;
	}

	for (int i = 0; dq_envs[i]; i++)
		printf("VALUES[%d]: %s\n", i, dq_envs[i]);

	// TODO : strjoin이나 append 2번 이용해서 이어 붙이기
	char *TEMP = ft_strdup(token);
	int count = 0;
	j = 0;
	i = 0;
	while (TEMP[i])
	{
		if (TEMP[i] == '$' && TEMP[i + 1] != ' ')
		{
			env_key_len = 0;
			while (TEMP[i + env_key_len])
			{
				if (TEMP[i + env_key_len] == ' ')
					break ;
				if (TEMP[i + env_key_len + 1] == '$')
				{
					env_key_len++;
					break ;
				}
				env_key_len++;
			}
			TEMP[i] = 0;
			converted_token = ft_strappend(converted_token, &TEMP[j]);
			converted_token = ft_strappend(converted_token, dq_envs[count]);
			i += env_key_len;
			count++;
			j = i;
			continue ;
		}
		i++;
	}
	converted_token = ft_strappend(converted_token, &TEMP[j]);
	printf("CONVERTED TOKEN : %s\n", converted_token);

	i = 0;
	while (i < dollor_count)
	{
		free(dq_envs[i]);
		i++;
	}
	free(dq_envs);
	free(token);
	free(TEMP);

	// converted_token = NULL;
	return (converted_token);

	}
	return (token);
}



char	*convert_dq_token(char *token)
{
	// char *converted_token;
	// int i;
	// int size;
	char *tmp;
	// char *tmp2;

	// 1. remove double quotes
	// 2. backslash
	// 3. env
	tmp = handling_dq_doublequotes(token);
	tmp = handling_dq_backslash(tmp);
	tmp = handling_dq_env(tmp);

	// printf("dq parsing: %s\n", tmp2);
	// char *str = ft_strdup("hello");
	// char *str1 = ft_strdup("world");
	// str[2] = 0;
	// str = ft_strappend(str, str1);
	// printf("test: %s\n", str);


	return (tmp);
}
