/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:34:02 by arivet            #+#    #+#             */
/*   Updated: 2026/05/25 14:01:54 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write (fd, "-", 1);
	}
	if (nb == 0)
	{
		(write(fd, "0", 1));
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd (nb / 10, fd);
		nb %= 10;
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
}
