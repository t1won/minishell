/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:42 by tseo              #+#    #+#             */
/*   Updated: 2021/03/11 10:35:26 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**g_envs;
int	g_exit_status;

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
	// char	**args;
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
		status = ft_execute(temp_args);
		for (int i = 0; temp_args[i]; i++)
			free(temp_args[i]);
		free(temp_args);
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
	// free(g_envs);
	run_minishell();


	return EXIT_SUCCESS;
}
