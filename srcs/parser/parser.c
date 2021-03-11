/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:45:24 by tseo              #+#    #+#             */
/*   Updated: 2021/03/11 11:55:59 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		convert_tokens(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '\'')
			tokens[i] = convert_sq_token(tokens[i]);
		if (tokens[i][0] == '$')
			tokens[i] = convert_env_token(tokens[i]);
		if (tokens[i][0] == '\"')
			tokens[i] = convert_dq_token(tokens[i]);
		i++;
	}
	return (1);
}

char	**tokenize_input_line(char *line)
{
	char	**tokens;
	int		token_num;
	int		i;

	token_num = count_tokens(line);
	if (!(tokens = (char **)malloc(sizeof(char *) * (token_num + 1))))
		memory_alloc_error();
	i = -1;
	while (++i < token_num)
		tokens[i] = get_token(line, i + 1);
	tokens[i] = NULL;
	return (tokens);
}

// TODO: 구조체로 변환해서 내보내기로 변환해야 한다
char	**parse_input_line(char *line)
{
	char **tokens= tokenize_input_line(line); // TODO : must be freed

	if (!check_tokens(tokens))
		return (0);
	convert_tokens(tokens);
	for (int i = 0; tokens[i]; i++)
			printf("[%d]: %s\n", i, tokens[i]);

	return (tokens);
}
