/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_conversion_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:24:29 by tseo              #+#    #+#             */
/*   Updated: 2021/03/11 11:23:05 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char *convert_sq_token(char *token)
{
	int i;
	int j;
	int size;
	char *converted_token;

	i = 0;
	size = 0;
	while (token[i])
	{
		if (token[i] != '\'')
			size++;
		i++;
	}
	if (!(converted_token = (char *)malloc(sizeof(char) * (size + 1))))
		memory_alloc_error();
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] != '\'')
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

char	*convert_env_token(char *token)
{
	char *converted_token;

	converted_token = NULL;
	if (ft_strlen(token) == 2 && ft_strncmp(token, "$?", 2) == 0)
		converted_token = ft_strdup(ft_itoa(g_exit_status));
	if (get_envs_value(&token[1]))
		converted_token = ft_strdup(get_envs_value(&token[1]));
	else
		converted_token = ft_strdup(""); // TODO: need to be fixed when tokens are put on the linked list
	free(token);
	return (converted_token);
}
