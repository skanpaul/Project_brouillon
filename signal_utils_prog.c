/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils_prog.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/17 15:20:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		write(1, MSG_SIGINT_PROG, strlen(MSG_SIGINT_PROG));
	}

	if (sig_code == SIGQUIT)
	{
		write(1, MSG_SIGQUIT_PROG, strlen(MSG_SIGQUIT_PROG));
	}

}
/* ************************************************************************** */