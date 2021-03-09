/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:42 by tseo              #+#    #+#             */
/*   Updated: 2021/03/09 09:25:17 by tseo             ###   ########.fr       */
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


void	run_minishell()
{
	char	*line;
	char	**args;
	int		status;
	char	**temp_args;

	status = 1;
	while (status)
	{
		handle_main_signals();
		print_prompt();
		get_input_line(&line); // TODO : EOF
		temp_args = parse_input_line(line);
		int i = 0;
		args = ft_split_line(line);
		status = ft_execute(args);
		free(line);
			i++;
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
