/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:11:16 by arivet            #+#    #+#             */
/*   Updated: 2026/06/09 15:31:00 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_write(unsigned int n, int len, int zeros, t_format *fmt)
{
	int	pad;
	int	printed;

	pad = 0;
	printed = 0;
	if (fmt->width > (len + zeros))
		pad = fmt->width - (len + zeros);
	if (fmt->zero == 1 && fmt->dot == 0 && fmt->minus == 0)
	{
		zeros += pad;
		pad = 0;
	}
	if (fmt->minus == 0 && pad > 0)
		printed += ft_printpad(' ', pad);
	if (zeros > 0)
		printed += ft_printpad('0', zeros);
	if (len > 0)
		printed += ft_putnbr_u(n);
	if (fmt->minus == 1 && pad > 0)
		printed += ft_printpad(' ', pad);
	return (printed);
}

int	ft_printunint(unsigned int n, t_format *fmt)
{
	int	len;
	int	zeros;

	zeros = 0;
	len = ft_nbrlen_u(n);
	if (n == 0 && fmt->dot == 1 && fmt->precision == 0)
		len = 0;
	if (fmt->dot == 1 && fmt->precision > len)
		zeros = fmt->precision - len;
	return (ft_printf_write(n, len, zeros, fmt));
}
