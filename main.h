/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:35:43 by ski               #+#    #+#             */
/*   Updated: 2022/04/17 13:54:20 by ski              ###   ########.fr       */
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
# define MSG_PROMPT		"ski_shell> "

# define MSG_A			"\n AAAA "
# define MSG_B			"\n BBBB "
# define MSG_C			"\n CCCC "
# define MSG_D			"\n DDDD "
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
	struct sigaction	sa_signal_main;
	struct sigaction	sa_signal_prog;
	//-------------------------------------------
	pid_t	pid_parent;
	pid_t	pid_process;
	pid_t	pid_child;


} t_data;
/* ************************************************************************** */
void	init_minishell(t_data *d);

/* ************************************************************************** */
void	init_sa_struct_main(t_data *d);
void	handler_signal_main(int sig_code);
void	init_sigaction_main(t_data *d);

/* ************************************************************************** */
void	init_sa_struct_prog(t_data *d);
void	handler_signal_prog(int sig_code);
void	init_sigaction_prog(t_data *d);

/* ************************************************************************** */
bool	is_child(pid_t fk_id);
bool	is_parent(pid_t fk_id);

/* ************************************************************************** */
#endif
