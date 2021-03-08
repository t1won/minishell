/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:12:58 by tseo              #+#    #+#             */
/*   Updated: 2021/03/07 19:38:37 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**tokenize_input(char *line)
{
	char	**tokens;
	int		size;
	int		i;

	size = count_tokens(line);
	if (!(tokens = (char **)malloc(sizeof(char *) * (size + 1))))
		memory_alloc_error();
	i = -1;
	while (++i < size)
		tokens[i] = split_line(line, i + 1);
	tokens[i] = NULL;
	return (tokens);
}
