/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:26:16 by elisa             #+#    #+#             */
/*   Updated: 2023/02/27 00:25:14 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		ft_putchar_fd(s[a], fd);
		a++;
	}
}

size_t	ft_strlen(const char *s)
{
	int	e;

	e = 0 ;
	if (!s)
		return (0);
	while (s[e] != '\0')
		e++;
	return (e);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

char	*ft_strjoin(char const *s1, char const s2)
{
	char	*result;
	int		len_s1;
	int		n;

	n = 0;
	len_s1 = ft_strlen(s1);
	result = malloc(sizeof(char) * (len_s1 + 1) + 1);
	if (len_s1 == 0)
	{
		result[0] = s2;
		result[1] = '\0';
		return (result);
	}
	while (n < len_s1)
	{
		result[n] = s1[n];
		n++;
	}
	result[n++] = s2;
	result[n] = '\0';
	return (result);
}
