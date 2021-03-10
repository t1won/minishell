/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:20:46 by tseo              #+#    #+#             */
/*   Updated: 2021/03/10 20:15:48 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		syntax_error(char *token)
{
	printf("minishell: syntax error near unexpected token '%s'\n", token);
	g_exit_status = 258;
	return (0);
}

int		no_command_error(char *cmd)
{
	printf("minishell: command not found: %s\n", cmd);
	g_exit_status = 127;
	return (0);
}

int		too_many_args_error(char *cmd)
{
	printf("minishell: too many arguments: %s\n", cmd);

	return (0);
}
