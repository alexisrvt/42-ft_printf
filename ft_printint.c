/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:05:30 by arivet            #+#    #+#             */
/*   Updated: 2026/06/09 14:15:05 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getpad(int n, int len, int zeros, t_format *fmt)
{
	int	pad;
	int	signlen;

	pad = 0;
	signlen = 0;
	if (n < 0 || fmt->plus == 1 || fmt->space == 1)
		signlen = 1;
	if (fmt->width > (len + signlen + zeros))
		pad = fmt->width - (len + signlen + zeros);
	return (pad);
}

static int	ft_putsign(int n, t_format *fmt)
{
	if (n < 0)
		return (write(1, "-", 1));
	else if (fmt->plus == 1)
		return (write(1, "+", 1));
	else if (fmt->space == 1)
		return (write(1, " ", 1));
	return (0);
}

static int	ft_printf_write(int n, int len, int zeros, t_format *fmt)
{
	int		printed;
	long	nb;
	int		pad;

	printed = 0;
	pad = ft_getpad(n, len, zeros, fmt);
	if (fmt->zero == 1 && fmt->dot == 0 && fmt->minus == 0)
	{
		zeros += pad;
		pad = 0;
	}
	nb = n;
	if (nb < 0)
		nb = -nb;
	if (fmt->minus == 0 && pad > 0)
		printed += ft_printpad(' ', pad);
	printed += ft_putsign(n, fmt);
	if (zeros > 0)
		printed += ft_printpad('0', zeros);
	if (len > 0)
		printed += ft_putnbr_abs(nb);
	if (fmt->minus == 1 && pad > 0)
		printed += ft_printpad(' ', pad);
	return (printed);
}

int	ft_printint(int n, t_format *fmt)
{
	int		len;
	int		zeros;
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	len = ft_nbrlen(nb);
	if (nb == 0 && fmt->dot == 1 && fmt->precision == 0)
		len = 0;
	zeros = 0;
	if (fmt->dot == 1 && fmt->precision > len)
		zeros = fmt->precision - len;
	return (ft_printf_write(n, len, zeros, fmt));
}
