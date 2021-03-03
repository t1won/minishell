/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:42 by tseo              #+#    #+#             */
/*   Updated: 2021/03/03 19:45:54 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**g_envp;

// gnl
// 1 : if can be read line
// 0 : if reached EOF
// -1 : if occured an error
int		get_input_line(char **line)
{
	int		ret;
	char	*input;
	// char	*tmp;

	*line = ft_strdup("");
	while (1)
	{
		ret = get_next_line(STDIN, &input);
		*line = ft_strappend(*line, input);
	}
}

void	run_minishell()
{
	char	*line;
	// char	**args;
	int		status;

	// TODO: handle_signal();

	status = 1;
	while (status != 0)
	{
		handle_main_signals();
		print_prompt();
		status = get_input_line(&line); // read a command line
		// args = split_line(line); // tokenize
		// status = execute_command(args); // using status determine when to exit

		// free(line);
		// free(args);
		break ;
	}
}

int		main(int argc, char **argv, char **envp)
{
	// TODO : initialize variables
	// TODO : show ascii art

	(void)argc;
	(void)argv;

	copy_environment_variables(envp);
	// run_minishell();

	return EXIT_SUCCESS;
}
