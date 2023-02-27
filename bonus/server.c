/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:07:50 by elisa             #+#    #+#             */
/*   Updated: 2023/02/27 15:39:11 by elisa            ###   ########.fr       */
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

void	recep(int s, siginfo_t *sigt, void	*a)
{
	static char	*stock;
	static char	c = 0;
	static int	i = 0;

	(void)a;
	c |= s == SIGUSR1;
	i++;
	if (i < 8)
		c = c << 1;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putstr_fd(stock, 1);
			ft_putstr_fd("\n", 1);
		}
		stock = ft_free(stock, c);
		i = 0;
		c = 0;
	}
	usleep(200);
	kill(sigt->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	aff_pid();
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = recep;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
