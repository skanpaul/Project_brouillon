/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/15 16:23:37 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void	handler_sigint(int sig_code)
{
	// printf("SIGNAL: %d\n", sig_code);
	write(1, MSG_SIGINT, strlen(MSG_SIGINT));
}

// ---------------------------------------------------------------------------
void	handler_sigquit(int sig_code)
{
	// printf("SIGNAL: %d\n", sig_code);
	// write(1, MSG_SIGQUIT, strlen(MSG_SIGQUIT));
}

/* ************************************************************************** */
void	handler_sigint_prog(int sig_code)
{
	// printf("SIGNAL: %d\n", sig_code);
	write(1, MSG_SIGINT, strlen(MSG_SIGINT));
}

// ---------------------------------------------------------------------------
void	handler_sigquit_prog(int sig_code)
{
	// printf("SIGNAL: %d\n", sig_code);
	// write(1, MSG_SIGQUIT, strlen(MSG_SIGQUIT));
}

/* ************************************************************************** */