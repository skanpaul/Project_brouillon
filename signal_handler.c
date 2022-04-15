/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/15 09:10:14 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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