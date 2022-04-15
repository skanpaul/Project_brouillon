/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:08:25 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/15 15:14:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void init_minishell(t_data *d)
{
	d->new_line = NULL;
    // init_signal(d);
	
}

/* ************************************************************************** */
void	init_signal(t_data *d)
{
    //ctrl-C: SIGINT -------------------------------------
    d->struct_sigint.sa_handler = &handler_sigint;
    sigemptyset(&d->struct_sigint.sa_mask);
    sigaddset(&d->struct_sigint.sa_mask, SIGINT);
    sigaddset(&d->struct_sigint.sa_mask, SIGQUIT);
    d->struct_sigint.sa_flags = SA_RESTART;
    sigaction(SIGINT, &d->struct_sigint, NULL);	
    
    //ctrl-\: SIGQUIT -----------------------------------
    d->struct_sigquit.sa_handler = &handler_sigquit;
    sigemptyset(&d->struct_sigquit.sa_mask);
    sigaddset(&d->struct_sigquit.sa_mask, SIGINT);
    sigaddset(&d->struct_sigquit.sa_mask, SIGQUIT);
    d->struct_sigquit.sa_flags = SA_RESTART;
    sigaction(SIGQUIT, &d->struct_sigquit, NULL);	

	//-------------------------------------
   
}
/* ************************************************************************** */