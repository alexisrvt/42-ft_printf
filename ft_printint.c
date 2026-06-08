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

static int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

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
	int		numlen;
	int		numzero;

	printed = 0;
	nb = n;
	if (nb < 0)
		nb = -nb;
	numlen = ft_numlen(nb);
	if (nb == 0 && fmt->dot == 1 && fmt->precision == 0)
		numlen = 0;
	if (fmt->dot == 1 && fmt->precision > numlen)
		numzero = fmt->precision - numlen;
	if (n >= 0)
	{
		if (fmt->plus == 1)
			printed += write(1, "+", 1);
		else if (fmt->space == 1)
			printed += write(1, " ", 1);
	}
	else
		printed += write (1, "-", 1);
	if (numzero > 0)
		printed += ft_printpad('0', numzero);
	if (numlen > 0)
		printed += ft_putabsnbr(nb);
	return (printed);
}