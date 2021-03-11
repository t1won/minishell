/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:46:36 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/12 02:10:18 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

#define PATH_MAX 1024

int	ft_pwd(char **cmd_line)
{
	char buf[PATH_MAX];

	(void)cmd_line;
	if (getcwd(buf, PATH_MAX) == NULL)
	{
		printf("current working directory get error: %s\n", strerror(errno));
		return (-1);
	}
	printf("%s\n", buf);
	return (0);
}