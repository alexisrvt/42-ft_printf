/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:05:30 by arivet            #+#    #+#             */
/*   Updated: 2026/06/08 16:58:55 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putabsnbr(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putabsnbr(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_printint(int n, t_format *fmt)
{
	int		printed;
	long	nb;

	printed = 0;
	nb = n;
	if (nb >= 0)
	{
		if (fmt->plus == 1)
			printed += write(1, "+", 1);
		else if (fmt->space == 1)
			printed += write(1, " ", 1);
	}
	else if (nb < 0)
	{
		printed += write (1, "-", 1);
		nb = -nb;
	}
	printed += ft_putabsnbr(nb);
}