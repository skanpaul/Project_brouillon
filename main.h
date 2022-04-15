/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:35:43 by ski               #+#    #+#             */
/*   Updated: 2022/04/15 16:50:33 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
/* ************************************************************************** */
# include <readline/readline.h>
# include <readline/history.h>
//---------------------------------
# include <sys/types.h>                                                                  
# include <sys/wait.h> 
/* ************************************************************************** */
# include <signal.h>
/* ************************************************************************** */
# define MSG_PROMPT		"SKI_SHELL BOUCLE> "
# define MSG_SIGINT		"\nSKI_SHELL> "
# define MSG_SIGQUIT	"\nSIGQUIT "
/* ************************************************************************** */
# define CMD_MAIN		"./main"
# define CMD_EXIT		"exit"
/* ************************************************************************** */
# define FK_CHILD		0
# define FK_ERROR		-1
/* ************************************************************************** */
# define STRCMP_EQU		0
/* ************************************************************************** */
typedef struct s_data
{
	char				*new_line;
	//-------------------------------------------
	struct sigaction	struct_sigint;	
	struct sigaction	struct_sigquit;
	//-------------------------------------------
	pid_t	pid_parent;
	pid_t	pid_process;
	pid_t	pid_child;


} t_data;
/* ************************************************************************** */
void	handler_sigint(int sig_code);
void	handler_sigquit(int sig_code);
// void	signal_handler(int sig_code);
/* ************************************************************************** */
void	init_minishell(t_data *d);
void	init_signal(t_data *d);
/* ************************************************************************** */
bool	is_child(pid_t fk_id);
bool	is_parent(pid_t fk_id);
/* ************************************************************************** */
#endif
