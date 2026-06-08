/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:19 by arivet            #+#    #+#             */
/*   Updated: 2026/06/07 13:58:19 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str_limit(char *str, int limit);

int	print_string(char *str, t_format *fmt)
{
	int	len;
	int	printed;

	printed = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fmt->dot == 1 && fmt->precision < len)
		len = fmt->precision;
	if (fmt->minus == 1)
	{
		printed += print_str_limit(str, len);
		if (fmt->width > len)
			printed += print_padding(' ', fmt->width - len);
	}
	else
	{
		if (fmt->width > len)
			printed += print_padding(' ', fmt->width - len);
		printed += print_str_limit(str, len);
	}
	return (printed);
}

int	print_str_limit(char *str, int limit)
{
	int	count;

	count = 0;
	while (limit > 0 && *str)
	{
		count += write(1, str, 1);
		str++;
		limit--;
	}
	return (count);
}