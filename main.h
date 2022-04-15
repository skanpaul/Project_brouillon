/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:35:43 by ski               #+#    #+#             */
/*   Updated: 2022/04/15 09:11:15 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
/* ************************************************************************** */
# include <signal.h>
/* ************************************************************************** */
# define MSG_PROMPT		"SKI_SHELL>"
# define MSG_SIGINT		"\nSKI_SHELL>"
# define MSG_SIGQUIT	"\nSIGQUIT"
/* ************************************************************************** */
typedef struct s_data
{
	char				*new_line;
	struct sigaction	sa;	
	// autre variable
	// autre variable

} t_data;
/* ************************************************************************** */
void	signal_handler(int sig_code);
void	init_minishell(t_data *d);

/* ************************************************************************** */
#endif
