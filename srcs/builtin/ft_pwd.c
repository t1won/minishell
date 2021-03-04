/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:46:36 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/04 21:49:06 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

#define PATH_MAX 1024

int	ft_pwd()
{
	char buf[PATH_MAX];

	if(getcwd(buf,PATH_MAX) == NULL)
	{
		printf("current working directory get error: %s\n", strerror(errno));
		return (-1);
	}
	printf("%s\n", buf);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	ft_pwd();
}
