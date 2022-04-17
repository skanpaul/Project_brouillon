/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:48:10 by ski               #+#    #+#             */
/*   Updated: 2022/04/17 15:00:47 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main(void)
{
	t_data d;

	pid_t fk_id;
	char *arg_exec[] = {"./main", NULL};	

	init_sa_struct_main(&d);
	init_sa_struct_prog(&d);
	
	fk_id = fork();	
	//-------------------------------------------------------
	if (is_parent(fk_id))
	{
		printf("parent PID %d\n", getpid());
		init_sigaction_main(&d);
		wait(NULL);
		printf("PARENT: code finished\n");
	}
	
	//-------------------------------------------------------
	if (is_child(fk_id))
	{
		d.new_line = NULL;
		
		
		printf("child PID %d\n", getpid());
		init_sigaction_prog(&d);	

		
		while(1)
		{
			d.new_line = readline(MSG_PROMPT);
			
			// if (strcmp(d.new_line, CMD_MAIN) == STRCMP_EQU)
			// 	execve(CMD_MAIN, arg_exec, NULL);
				
			// else if ( strcmp(d.new_line, CMD_EXIT) == STRCMP_EQU)
			// 	break;
			
			free(d.new_line);
		}
		printf("CHILD: code finished\n");
	}
	//-------------------------------------------------------
	return (0);
}
	
/* ************************************************************************** */