/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:45:24 by tseo              #+#    #+#             */
/*   Updated: 2021/03/09 20:00:48 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		skip_separator_spaces(char *line, int i)
{
	int skip;

	if (line[i] == ' ' || line[i] == '\t')
		skip = 1;
	else if (line[i] == '>' && line[i + 1] == '>')
		skip = 2;
	else if (line[i] == '>')
		skip = 1;
	else if (line[i] == '<')
		skip = 1;
	else if (line[i] == '|')
		skip = 1;
	else if (line[i] == ';')
		skip = 1;
	else
		return (0);
	i += skip;
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
		skip++;
	}
	return (skip);
}

int		skip_separator(char *line, int i)
{
	int skip;

	skip = 0;
	if (line[i] == ' ' || line[i] == '\t')
		skip = 1;
	else if (line[i] == '>' && line[i + 1] == '>')
		skip = 2;
	else if (line[i] == '>')
		skip = 1;
	else if (line[i] == '<')
		skip = 1;
	else if (line[i] == '|')
		skip = 1;
	else if (line[i] == ';')
		skip = 1;
	return (skip);
}

int		check_backslash(char *line, int *i, char quote)
{
	if (!line[*i])
		return (0);
	if (line[*i] == '\\')
		++*i;
	else if (line[*i] == quote)
		return (0);
	return (1);
}

// TODO : flag를 이용해서 최적화
int		check_and_jmp_quotes(char *line, int i)
{
	// int	sq_flag;
	// int	dq_flag;

	// sq_flag = 1;
	// dq_flag = 1;
	if (line[i] == '\"' && (i == 0 || line[i - 1] != '\\'))
	{
		i++;
		while (check_backslash(line, &i, '\"'))
			i++;
		if (line[i] =='\0')
		{
			printf("Syntax Error: Quotes are not matched\n");
			return (-1);
		}
	}
	else if (line[i] == '\'')
	{
		i++;
		while (line[i] != '\'' && line[i])
			i++;
		if (line[i] =='\0')
		{
			printf("Syntax Error: Quotes are not matched\n");
			return (-1);
		}
	}
	return (i);
}


int		count_tokens(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (!is_separtor(SEPARATOR_SPACE, line[i]) && line[i])
		{
			count++;
			while (!is_separtor(SEPARATOR_SPACE, line[i]) && line[i])
			{
				if ((i = check_and_jmp_quotes(line, i)) == -1)
					return (0);
				if (line[i] == '\\' && !line[i + 1])
					return (0);
				i++;
			}
		}
		else if (is_separtor(SEPARATOR, line[i]))
			count++;
		i += skip_separator_spaces(line, i);
	}
	printf("TOKEN COUNT: %d\n", count);
	return (count);
}

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
	for (int i = 0; tokens[i]; i++)
			printf("[%d]: %s\n", i, tokens[i]);
	return (tokens);
}

// TODO: 구조체로 변환해서 내보내기로 변환해야 한다
char	**parse_input_line(char *line)
{
	char **temp_line = tokenize_input_line(line);

	return (temp_line);
}
