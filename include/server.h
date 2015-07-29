/*
** server.h for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minitalk
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Wed Feb 25 14:40:39 2015 Julien Karst
** Last update Sun Mar 22 11:53:47 2015 Julien Karst
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

typedef struct	s_all
{
  int		pid;
  int		i;
  char		c;
  char		b;
  char		ok;
}		t_all;

extern t_all	*a;

void		print_char(char b);
void		catch_pid(char b);
void		my_signal(int sig);
void		catch_signal();
void		aff_pid();
void		my_sign1();
void		my_sign2();
void		raz();

#endif /* SERVER_H_ */
