/*
** client2.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minitalk
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Mar 12 13:53:35 2015 Julien Karst
** Last update Sun Mar 22 21:57:43 2015 Julien Karst
*/

#include "client.h"

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
