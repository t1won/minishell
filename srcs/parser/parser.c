/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:45:24 by tseo              #+#    #+#             */
/*   Updated: 2021/03/08 19:11:04 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  1. 토큰화
**	2. 토큰 별로 처리
**	3. 구조체에 저장 후 링크드 리스트에 저장
*/

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

int		get_token_num(char *line)
{
	int count;
	int i;
	int sq_flag;
	int dq_flag;

	sq_flag = 1; // 1이면 single quotes는 닫혀있는 상태
	dq_flag = 1; // 1이면 double quotes는 닫혀있는 상태
	count = 0;
	i = 0;
	while (line[i])
	{
		if (sq_flag == 1 && dq_flag == 1 && line[i] == ' ')
			count++;
		if (dq_flag == 1 && line[i] == '\'')
			sq_flag *= -1;
		if (sq_flag == 1 && i > 1 && line[i - 1] != '\\' && line[i] == '"')
			dq_flag *= -1;
		i++;
	}
	return (count);
}

// 반환을 링크드 리스트의 head 포인터로 변환해야 한다
void	parse_input(char *cmd_line)
{
	// int		token_num;
	// printf("parse: %s\n", cmd_line);
	(void)cmd_line;

	// char *test = "a\\b d\"e f\"g h";
	printf("token num: %d\n", get_token_num(cmd_line));


}
