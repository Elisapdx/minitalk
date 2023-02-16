/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:50:15 by elisa             #+#    #+#             */
/*   Updated: 2023/02/16 16:54:04 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	aff_pid(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	recep(int s)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= s == SIGUSR1;
	i++;
	if (i < 8)
		c = c << 1;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	usleep(200);
}

int	main(void)
{
	aff_pid();
	signal(SIGUSR1, recep);
	signal(SIGUSR2, recep);
	while (1)
		pause();
	return (1);
}
