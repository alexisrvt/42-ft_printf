/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:56:51 by arivet            #+#    #+#             */
/*   Updated: 2026/06/09 16:19:51 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthash(int isupper)
{
	if (isupper == 1)
		return (write(1, "0X", 2));
	return (write(1, "0x", 2));
}

static int	ft_hexpad(unsigned int n, int len, int zeros, t_format *fmt)
{
	int	pad;
	int	hashlen;

	pad = 0;
	hashlen = 0;
	if (fmt->hash == 1 && n != 0)
		hashlen = 2;
	if (fmt->width > (len + zeros + hashlen))
		pad = fmt->width - (len + zeros + hashlen);
	return (pad);
}

static int	ft_printf_write(unsigned int n, int len, int zeros, t_format *fmt)
{
	int	pad;
	int	printed;

	printed = 0;
	pad = ft_hexpad(n, len, zeros, fmt);
	if (fmt->zero == 1 && fmt->dot == 0 && fmt->minus == 0)
	{
		zeros += pad;
		pad = 0;
	}
	if (fmt->minus == 0 && pad > 0)
		printed += ft_printpad(' ', pad);
	if (fmt->hash == 1 && n != 0)
		printed += ft_puthash(fmt->type == 'X');
	if (zeros > 0)
		printed += ft_printpad('0', zeros);
	if (len > 0)
		printed += ft_puthex(n, fmt->type == 'X');
	if (fmt->minus == 1 && pad > 0)
		printed += ft_printpad(' ', pad);
	return (printed);
}

int	ft_printhex(unsigned int n, t_format *fmt)
{
	int	len;
	int	zeros;

	zeros = 0;
	len = ft_hexlen(n);
	if (n == 0 && fmt->dot == 1 && fmt->precision == 0)
		len = 0;
	if (fmt->dot == 1 && fmt->precision > len)
		zeros = fmt->precision - len;
	return (ft_printf_write(n, len, zeros, fmt));
}
