/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/17 14:33:08 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void init_sa_struct_main(t_data *d)
{
	// SA_HANDLER -------------------------------------
	d->sa_signal_main.sa_handler = &handler_signal_main;
	// SA_MASK ----------------------------------------
	sigemptyset(&d->sa_signal_main.sa_mask);
	sigaddset(&d->sa_signal_main.sa_mask, SIGINT);
	sigaddset(&d->sa_signal_main.sa_mask, SIGQUIT);
	// SA_FLAG ----------------------------------------
	d->sa_signal_main.sa_flags = SA_RESTART;	
}

/* ************************************************************************** */
void	handler_signal_main(int sig_code)
{
	if (sig_code == SIGINT)
	{
		write(1, MSG_A, strlen(MSG_A));
	}	
	if (sig_code == SIGQUIT)
	{
		write(1, MSG_B, strlen(MSG_B));
	}
}

/* ************************************************************************** */
void init_sigaction_main(t_data *d)
{
	// SIGACTION --------------------------------------
	sigaction(SIGINT, &d->sa_signal_main, NULL);	// [ctrl-C]: SIGINT
	sigaction(SIGQUIT, &d->sa_signal_main, NULL);	// [ctrl-\]: SIGQUIT	
}

/* ************************************************************************** */
void init_sa_struct_prog(t_data *d)
{
	// SA_HANDLER ---------------------------------------------
	d->sa_signal_prog.sa_handler = &handler_signal_prog;	
	// SA_MASK ------------------------------------------------
	sigemptyset(&d->sa_signal_prog.sa_mask);
	sigaddset(&d->sa_signal_prog.sa_mask, SIGINT);
	sigaddset(&d->sa_signal_prog.sa_mask, SIGQUIT);
	// SA_FLAG ------------------------------------------------
	d->sa_signal_prog.sa_flags = SA_RESTART;	
}
/* ************************************************************************** */
void	init_sigaction_prog(t_data *d)
{
	// SIGACTION ----------------------------------------------
	sigaction(SIGINT, &d->sa_signal_prog, NULL);	// [ctrl-C]: SIGINT
	sigaction(SIGQUIT, &d->sa_signal_prog, NULL);	// [ctrl-\]: SIGQUIT
}

/* ************************************************************************** */
void	handler_signal_prog(int sig_code)
{
	if (sig_code == SIGINT)
	{
		write(1, MSG_C, strlen(MSG_C));
	}

	if (sig_code == SIGQUIT)
	{
		write(1, MSG_D, strlen(MSG_D));
	}

}
/* ************************************************************************** */