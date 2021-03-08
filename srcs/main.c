/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:42 by tseo              #+#    #+#             */
/*   Updated: 2021/03/08 11:39:52 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**g_envp;

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

int lsh_num_builtins()
{
	return (sizeof(builtin_str) / sizeof(char *));
}


// main loop
void	run_minishell()
{
	char	*line;
	char	**args;
	int		status;
	char **input_lines;

	status = 1;
	while (status)
	{
		handle_main_signals();
		print_prompt();
		get_input_line(&line);
		input_lines = ft_split(line, ';');
		// parse_input(line, input_lines);
		for (int i = 0; input_lines[i]; i++)
			printf("[%d] : %s\n", i, input_lines[i]);

		int i = 0;
		while (input_lines[i])
		{
			args = ft_split_line(input_lines[i]);
			status = ft_execute(args);
			free(input_lines[i]); // memory leak
			i++;
		}
		// parse_input(line, input_lines);
		// args = ft_split_line(line);
		// status = ft_execute(args);
		free(input_lines);
		free(line);
	}
}

int		main(int argc, char **argv, char **envp)
{
	// TODO : initialize variables
	// TODO : show ascii art

	(void)argc;
	(void)argv;

	copy_environment_variables(envp);
	run_minishell();


	return EXIT_SUCCESS;
}
