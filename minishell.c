/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:48:10 by ski               #+#    #+#             */
/*   Updated: 2022/04/15 15:14:37 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main(void)
{
	t_data d;

	pid_t fk_id;
	char *arg_exec[] = {"./main", NULL};

	init_minishell(&d);
	
	fk_id = fork();
	
	//-------------------------------------------------------
	if (is_child(fk_id))
	{
		d.new_line = NULL;	
		while(1)
		{
			printf("pid: %d\n", getpid());
			d.new_line = readline(MSG_PROMPT);
			
			if (strcmp(d.new_line, CMD_MAIN) == STRCMP_EQU)
				execve(CMD_MAIN, arg_exec, NULL);
				
			else if ( strcmp(d.new_line, CMD_EXIT) == STRCMP_EQU)
				break;
			
			free(d.new_line);
		}
		printf("CHILD: code finished\n");
	}
	//-------------------------------------------------------
	if (is_parent(fk_id))
	{
		d.new_line = NULL;
		d.pid_child = fk_id;
		d.pid_process = getpid();
		init_signal(&d);
		d.pid_child = fk_id;
		d.pid_process = getpid();
		wait(NULL);
		printf("PARENT: code finished\n");
	}
	//-------------------------------------------------------
	
	return (0);
}
	
/* ************************************************************************** */