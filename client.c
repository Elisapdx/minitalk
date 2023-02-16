/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:23:41 by elisa             #+#    #+#             */
/*   Updated: 2023/02/16 16:53:55 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	t_exit(int s)
{
	if (s == SIGUSR2)
		exit(1);
}

int	verif_pid(int pid)
{
	int	i;

	if (pid <= 0)
		return (0);
	i = 8;
	return (1);
	while (i-- && kill(pid, SIGUSR1) == 0)
	{
		usleep(200);
	}
	if (i == -1)
		return (1);
	return (0);
}

void	decal(unsigned char c, int pid)
{
	int	i;

	i = 8;
	while (i)
	{
		if ((c >> (i - 1)) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		if (verif_pid(pid))
		{
			while (argv[2][i] != '\0')
			{
				decal((unsigned char) argv[2][i], pid);
				i++;
			}
		}
		else
			ft_putstr_fd("Invalid PID\n", 1);
	}
	else
		ft_putstr_fd("Usage ./client <pid> <message>\n", 1);
	return (1);
}
