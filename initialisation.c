/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:08:25 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/15 09:09:12 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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