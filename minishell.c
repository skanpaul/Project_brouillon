/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:48:10 by ski               #+#    #+#             */
/*   Updated: 2022/04/17 20:39:09 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data d;
	pid_t fk_id;
	char *arg_exec[] = {"./main", NULL};	

	char *inputrc;

	inputrc = getenv("INPUTRC");
	printf("Salut: %s\n", inputrc);

	d.new_line = NULL;
	
	init_sa_struc_main(&d);
	init_sigaction_main(&d);
	
	//-------------------------------------------------------
	while (1)
	{
		d.new_line = readline(MSG_PROMPT);
		// if (strcmp(d.new_line, CMD_EXIT) == SAME_STRING)
		// 	break;
		
		if (d.new_line)
			free(d.new_line);
	}
	//-------------------------------------------------------
	
	return (0);
}
	
/* ************************************************************************** */





