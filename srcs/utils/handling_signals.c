/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:00:46 by tseo              #+#    #+#             */
/*   Updated: 2021/03/03 19:42:35 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	main_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		// errno = 1
		ft_putstr_fd("\b\b  \b\b", STDOUT);
		ft_putstr_fd("\n", STDERR_FILENO);
		print_prompt();
		signal(SIGINT, main_signal_handler);
	}
	else if (signo == SIGQUIT)
	{
		ft_putstr_fd("\b\b  \b\b", 1);
	}
}

void	child_signal_hanlder(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		signal(SIGINT, main_signal_handler);
	}
	if (signo == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
		signal(SIGQUIT, main_signal_handler);
	}
}

void	handle_main_signals(void)
{
	signal(SIGINT, main_signal_handler);
	signal(SIGQUIT, main_signal_handler);
}
