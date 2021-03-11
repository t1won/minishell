/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:19:11 by tseo              #+#    #+#             */
/*   Updated: 2021/03/11 16:28:32 by tseo             ###   ########.fr       */
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
