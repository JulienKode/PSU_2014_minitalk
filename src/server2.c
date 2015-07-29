/*
** server2.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minitalk/src
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Mar 12 10:51:30 2015 Julien Karst
** Last update Tue Mar 24 10:01:37 2015 Julien Karst
*/

#include "server.h"

void	aff_pid()
{
  my_printf("\033[31mServer PID : %d\033[0m\n\0", getpid());
  return ;
}

void	my_sign1()
{
  if ((kill(a->pid, 10)) == -1)
    my_exit2("Error -> Kill on SIGUSR1");
}

void	my_sign2()
{
  if ((kill(a->pid, 12)) == -1)
    my_exit2("Error -> Kill on SIGUSR2");
}

void	raz()
{
  a->i = 0;
  a->pid = 0;
  a->ok = 1;
  a->c = 0;
}
