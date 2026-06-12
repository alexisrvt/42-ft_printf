/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:38:46 by arivet            #+#    #+#             */
/*   Updated: 2026/06/12 12:26:29 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_putptr(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_putptr(n / 16);
	write(1, &base[n % 16], 1);
}

int	ft_printptr(void *p, t_format *fmt)
{
	unsigned long long	addr;
	int					len;
	int					pad;
	int					printed;

	addr = (unsigned long long)p;
	printed = 0;
	if (!addr)
		return (printed += write(1, "(nil)", 5));
	len = ft_ptrlen(addr);
	pad = 0;
	if (fmt->width > (len + 2))
		pad = fmt->width - (len + 2);
	if (fmt->minus == 0 && pad > 0)
		printed += ft_printpad(' ', pad);
	printed += write(1, "0x", 2);
	ft_putptr(addr);
	printed += len;
	if (fmt->minus == 1 && pad > 0)
		printed += ft_printpad(' ', pad);
	return (printed);
}
