/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:42 by tseo              #+#    #+#             */
/*   Updated: 2021/03/02 16:16:52 by tseo             ###   ########.fr       */
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

void	main_signal_handler(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			ft_putstr_fd("\b\b  \b\b\n", STDOUT);
			print_prompt();
			// g_exit_status = 1;
		}
		else
			ft_putchar_fd('\n', STDOUT);
	}
	else if (signo == SIGQUIT)
	{
		if (pid == -1)
			ft_putstr_fd("\b\b  \b\b", STDOUT);
		else
			ft_putstr_fd("Quit: 3\n", STDOUT);
	}
}

// TEMPTEMP
void	handle_signal(void)
{
	signal(SIGINT, main_signal_handler);
	signal(SIGQUIT, main_signal_handler);
}

void	run_minishell()
{
	handle_signal();
	while (1)
	{
		print_prompt();
	}

}

int		main(int argc, char **argv, char **envp)
{
	// TODO : initialize variables
	// TODO : set sigals
	// TODO : show ascii art

	// TEMP
	(void)argc;
	(void)argv;
	(void)envp;

	run_minishell();
	return 0;
}
