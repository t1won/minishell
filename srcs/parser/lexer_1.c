/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:19:15 by tseo              #+#    #+#             */
/*   Updated: 2021/03/10 20:11:15 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*get_token(char *line, int token_size)
{
	int i;
	int start_idx;
	int token_num;

	i = 0;
	start_idx = 0;
	token_num = 0;
	while (line[i])
	{
		if (!is_separtor(SEPARATOR_SPACE, line[i]) && line[i] && ++token_num)
		{
			while (!is_separtor(SEPARATOR_SPACE, line[i]) && line[i])
				i = check_and_jmp_quotes(line, i) + 1; // TODO : need to fixed
			if (token_num == token_size)
				return (ft_substr(line, start_idx, i - start_idx));
			start_idx = i;
		}
		if (is_separtor(SEPARATOR, line[i]) && ++token_num)
			if (token_num == token_size)
				return (ft_substr(line, start_idx, i + skip_separator(line, i) - start_idx));
		i += skip_separator_spaces(line, i);
		start_idx = i;
	}
	return (NULL);
}
