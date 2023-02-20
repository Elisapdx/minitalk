/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:50:15 by elisa             #+#    #+#             */
/*   Updated: 2023/02/20 13:48:23 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_free(char *buffer, char buf)
{
	char	*temp;

	if (buf)
	{
		temp = ft_strjoin(buffer, buf);
		free(buffer);
		return (temp);
	}
	else
	{
		free(buffer);
		return (NULL);
	}
}

void	aff_pid(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	recep(int s)
{
	static char	*stock;
	static char	c = 0;
	static int	i = 0;

	c |= s == SIGUSR1;
	i++;
	if (i < 8)
		c = c << 1;
	if (i == 8)
	{
		if (c == '\0')
			ft_putstr_fd(stock, 1);
		stock = ft_free(stock, c);
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
