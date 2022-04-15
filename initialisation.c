/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:08:25 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/15 09:32:05 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void init_minishell(t_data *d)
{
	d->new_line = NULL;
    init_signal(d);
	
}

/* ************************************************************************** */
void	init_signal(t_data *d)
{
    //ctrl-C: SIGINT -------------------------------------
    d->struct_sigint.sa_handler = &signal_handler;
    sigemptyset(&d->struct_sigint.sa_mask);
    sigaddset(&d->struct_sigint.sa_mask, SIGINT);
    sigaddset(&d->struct_sigint.sa_mask, SIGQUIT);
    d->struct_sigint.sa_flags = SA_RESTART;
    sigaction(SIGINT, &d->struct_sigint, NULL);	
    
    //ctrl-\: SIGQUIT -----------------------------------
    d->struct_sigquit.sa_handler = &signal_handler;
    sigemptyset(&d->struct_sigquit.sa_mask);
    sigaddset(&d->struct_sigquit.sa_mask, SIGINT);
    sigaddset(&d->struct_sigquit.sa_mask, SIGQUIT);
    d->struct_sigquit.sa_flags = SA_RESTART;
    sigaction(SIGQUIT, &d->struct_sigquit, NULL);	

	//-------------------------------------
	// d->sa.sa_handler = &handler_sig_usr;
	// d->sa.sa_flags = SA_RESTART;
	// sigemptyset(&d->sa.sa_mask);
	// sigaddset(&d->sa.sa_mask, SIGUSR1);
	// sigaddset(&d->sa.sa_mask, SIGUSR2);

    
}
/* ************************************************************************** */