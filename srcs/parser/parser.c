/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:45:24 by tseo              #+#    #+#             */
/*   Updated: 2021/03/08 11:10:10 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"


int		get_seperator_num(char *line)
{
	int i;
	int count = 0;
	int single_quotes_flag = 1;
	int double_quotes_flag = 1;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			single_quotes_flag *= -1;
		if (line[i] == '"')
			double_quotes_flag *= -1;
		if (single_quotes_flag == 1 &&
			double_quotes_flag &&
			line[i] == ';')
			count++;
		i++;
	}
	return (count);
}

// void	split_line_with_separator(char *line, char **input_lines, int s_num)
// {
// 	int i = 0;
// 	while ()
// }

void	parse_input(char *line, char **input_lines)
{
	int seperator_num;
	// int i = 0;
	(void)input_lines;
	seperator_num = get_seperator_num(line);
	// if (!(input_lines = malloc(sizeof(char **) * (seperator_num + 2))))
		// memory_alloc_error();
	// input_lines[seperator_num + 1] = NULL;
	printf("separtor num: %d\n", seperator_num);
	// while (i < seperator_num + 1)
	// {
	// 	split_line_with_separator()
	// }
}
