/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_conversion_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:43:53 by tseo              #+#    #+#             */
/*   Updated: 2021/03/11 20:27:54 by tseo             ###   ########.fr       */
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
char	*remove_dq(char *token)
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

char	*handling_backslash(char *token)
{
	int i;
	int j;
	int size;
	char *converted_token;

	i = 0;
	size = 0;
	while (token[i])
	{
		if (token[i] == '\\' && token[i + 1] == '\\')
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
		converted_token[j] = token[i];
		j++;
		i++;
	}
	converted_token[size] = 0;
	// printf("conveted: %s\n", converted_token);
	// free(token);
	// printf("SIZE: %d\n", size);
	return (converted_token);
}

char	*convert_dq_token(char *token)
{
	// char *converted_token;
	// int i;
	// int size;
	char *tmp;
	char *tmp2;

	// 1. remove double quotes
	// 2. backslash
	// 3. env
	tmp = remove_dq(token);
	tmp2 = handling_backslash(tmp);

	// printf("dq parsing: %s\n", tmp2);
	// char *str = ft_strdup("hello");
	// char *str1 = ft_strdup("world");
	// char *str2 = ft_strdup("");
	// str = ft_strappend(str, str2);
	// str = ft_strappend(str, str1);
	// printf("test: %s\n", str);


	return (tmp2);
}
