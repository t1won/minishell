/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:47:46 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/03 16:40:56 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include <stdio.h>

char	*g_builtin_str[] = {
	"echo",
	"cd",
	"pwd",
	"export",
	"unset",
	"env",
	"exit"
};

/*
int (*g_builtin_func[]) (char **) = {
	&ft_echo,
	&ft_cd,
	&ft_pwd,
	&ft_export,
	&ft_unset,
	&ft_env,
	&ft_exit
};
*/

void	exec_builtin(t_cmd stmt)
{
	int cnt;

	cnt = sizeof(g_builtin_str) / sizeof(char *);

	while (--cnt)
	{
		if (ft_strncmp(g_builtin_str[cnt], stmt.cmd, 8) == 0)
			return (g_builtin_func[cnt](stmt.values)); // opt + obj
	}

}

void	exec(t_list *head)
{
	t_list *curr;
	t_cmd *stmt;

	curr = head;
	while (curr)
	{
		stmt = curr->content;
		if (stmt->cmd)
		{
			if (stmt->flag == 1)
				printf("pipe\n"); //ft_pipe();
			else if (stmt->redir == 1)
				printf("redirecion\n"); //ft_redirection();
			else
				exec_builtin();
		}
		curr = curr->next;
	}
}

