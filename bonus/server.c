/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:07:50 by elisa             #+#    #+#             */
/*   Updated: 2023/02/18 18:40:34 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	aff_pid(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	recep(int s, siginfo_t *sigt, void	*a)
{
	static unsigned char	c = 0;
	static int				i = 0;

	(void)a;
	c |= s == SIGUSR2;
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
	kill(sigt->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	aff_pid();
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = recep;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (1);
}
