/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:56:18 by tseo              #+#    #+#             */
/*   Updated: 2021/03/11 00:26:37 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_prompt(void)
{
	// static char	*curpath;

	ft_putstr_fd(COLOR_BR_BLUE, STDOUT);
	write(STDOUT_FILENO, "minishell", 10);
	// ft_putstr_fd(getcwd(curpath, MAXSIZE), STDIN);
	ft_putstr_fd(COLOR_WHITE, STDOUT);
	ft_putstr_fd("$ ", STDOUT);
}

// show ascii arts
void	show_ascii_args(void)
{

}


void	copy_environment_variables(char **envs)
{
	int size;

	size = 0;
	while (envs[++size])
		size++;
	if (!(g_envs = malloc(sizeof(char *) * (size + 1))))
		exit(EXIT_FAILURE); // memory allocation failed
	size = -1;
	while (envs[++size])
		g_envs[size] = ft_strdup(envs[size]);
	g_envs[size] = NULL;
}
