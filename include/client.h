/*
** client.h for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minitalk
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Wed Feb 25 14:40:50 2015 Julien Karst
** Last update Sun Mar 22 11:55:36 2015 Julien Karst
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"

typedef struct	s_all
{
  int		mypid;
  int		i;
  int		l;
  char		b;
  int		pid;
  char		*str;
  char		c;
  char		ok;
}		t_all;

extern t_all	*a;

void		env_pid();
void		my_signal();
void		catch_signal();
void		env_etb();
void		my_sign1();
void		my_sign2();

#endif /* CLIENT_H_ */
