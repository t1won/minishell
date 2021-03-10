/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:34:54 by tseo              #+#    #+#             */
/*   Updated: 2021/03/10 20:32:19 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		is_separtor(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_redirection(char *token)
{
	if (ft_strncmp(token, "<", 1) == 0)
		return (1);
	if (ft_strncmp(token, ">", 1) == 0)
		return (1);
	if (ft_strncmp(token, ">>", 1) == 0)
		return (1);
	return (0);
}

int		is_pipe(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return (1);
	return (0);
}

int		is_semicolon(char *token)
{
	if (ft_strncmp(token, ";", 1) == 0)
		return (1);
	return (0);
}
