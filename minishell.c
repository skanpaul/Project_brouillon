/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:48:10 by ski               #+#    #+#             */
/*   Updated: 2022/04/13 16:27:38 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main(void)
{
	t_data d;
	// --------------------------------------
	d.new_line = NULL;
	// --------------------------------------
	
	init_minishell(&d);
	sigaction(SIGINT, &d.sa, NULL);
	// sigaction(, &d.sa, NULL);
	sigaction(SIGQUIT, &d.sa, NULL);
	
	while(1)
	{
		printf("pid: %d\n", getpid());
		d.new_line = readline(MSG_PROMPT);
		free(d.new_line);
	}
	return (0);
}

/* ************************************************************************** */
void	signal_handler(int sig_code)
{
	// ctrl-C -----------------------------
	if (sig_code == SIGINT)
	{
		// printf("\n%s", MSG_PROMPT);
		write(1, MSG_SIGINT, strlen(MSG_SIGINT));
	}
				
	// ctrl-D -----------------------------
	// else if (sig_code == )
	// 	printf("sorakann: \n");
		
	// ctrl-\ -----------------------------
	else if (sig_code == SIGQUIT)
	{
		// printf("SIGQUIT\n");
		write(1, MSG_SIGQUIT, strlen(MSG_SIGQUIT));
	}
	
}
/* ************************************************************************** */
void init_minishell(t_data *d)
{
	d->new_line = NULL;
	//-------------------------------------
	d->sa.sa_handler = &signal_handler;
	d->sa.sa_flags = SA_RESTART;
	sigemptyset(&d->sa.sa_mask);
	sigaddset(&d->sa.sa_mask, SIGINT);

	sigaddset(&d->sa.sa_mask, SIGQUIT);
	

	//-------------------------------------
	// d->sa.sa_handler = &handler_sig_usr;
	// d->sa.sa_flags = SA_RESTART;
	// sigemptyset(&d->sa.sa_mask);
	// sigaddset(&d->sa.sa_mask, SIGUSR1);
	// sigaddset(&d->sa.sa_mask, SIGUSR2);
}
	
/* ************************************************************************** */