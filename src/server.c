/*
** server.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minitalk/src
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Mar 12 10:40:45 2015 Julien Karst
** Last update Sun Mar 22 11:48:40 2015 Julien Karst
*/

#include "server.h"

t_all	*a;

void	print_char(char b)
{
  if (a->i < 8)
    {
      a->c += b << a->i;
      a->i++;
    }
  if (a->i >= 8)
    {
      if (a->c == 23)
	{
	  raz();
	  return ;
	}
      my_putchar(a->c);
      a->i = 0;
      a->c = 0;
    }
  my_sign1();
}

void	catch_pid(char b)
{
  if (a->i < 32)
    {
      a->pid += b << a->i;
      a->i++;
    }
  if (a->i >= 32)
    {
      usleep(1000);
      my_sign1();
      a->ok = 0;
      a->i = 0;
    }
}

void	my_signal(int sig)
{
  if (a->ok != 0)
    {
      if (sig == SIGUSR1)
	catch_pid(1);
      if (sig == SIGUSR2)
	catch_pid(0);
    }
  else
    {

      if (sig == SIGUSR1)
	print_char(1);
      if (sig == SIGUSR2)
	print_char(0);
    }
}

void	catch_signal()
{
  if ((signal(SIGUSR1, my_signal)) == SIG_ERR)
    my_exit("Error -> Signal Failed");
  if ((signal(SIGUSR2, my_signal)) == SIG_ERR)
    my_exit("Error -> Signal Failed");
}

int	main()
{
  if ((a = malloc(1 * sizeof(t_all))) == NULL)
    my_exit2("Error -> Malloc Failed");
  a->i = 0;
  a->pid = 0;
  a->ok = 1;
  catch_signal();
  aff_pid();
  while (pause());
}
