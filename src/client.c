/*
** client.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minitalk/src
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Mar 12 10:40:51 2015 Julien Karst
** Last update Sun Mar 22 21:58:15 2015 Julien Karst
*/

#include "client.h"

t_all	*a;

void	env_pid()
{
  while (a->i < 32)
    {
      if (((a->mypid >> a->i) & 1) == 1)
	my_sign1();
      else
	my_sign2();
      a->i++;
      usleep(1000);
    }
  a->i = 0;
}

void	my_signal()
{
  if (a->str[a->i])
    {
      if (a->l < 8)
	{
	  if (((a->str[a->i] >> a->l) & 1) == 1)
	    my_sign1();
	  else
	    my_sign2();
	  a->l++;
	}
      if (a->l >= 8)
	{
	  a->l = 0;
	  a->i++;
	}
      return ;
    }
  env_etb();
}

void	catch_signal()
{
  if ((signal(SIGUSR1, my_signal)) == SIG_ERR)
    my_exit2("Error -> Signal Failed");
}

int	main(int ac, char **argv)
{
  if (ac != 3)
    my_exit2("Error -> Exemple : ./client $PIDOFSERVER $MESSAGE");
  if ((a = malloc(1 * sizeof(t_all))) == NULL)
    my_exit2("Error -> Malloc Failed");
  my_printf("\033[32mClient PID : %d\033[0m\n\0", getpid());
  a->i = 0;
  a->ok = 23;
  a->l = 0;
  a->pid = my_getnbr(argv[1]);
  a->mypid = getpid();
  a->str = argv[2];

  catch_signal();
  a->l = 0;
  env_pid();
  while (pause());
}

void	env_etb()
{
  if (a->l < 8)
    {
      if (((a->ok >> a->l) & 1) == 1)
	my_sign1();
      else
	my_sign2();
      a->l++;
    }
  if (a->l >= 8)
    exit(1);
}
