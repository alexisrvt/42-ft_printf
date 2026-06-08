/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:07:52 by arivet            #+#    #+#             */
/*   Updated: 2026/06/06 19:15:45 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dispatch_conversion(t_format *fmt, va_list *ap)
{
	int	printed_chars;

	printed_chars = 0;
	if (fmt->type == 'c')
		printed_chars = print_char(va_arg(*ap, int), fmt);
	else if (fmt->type == 's')
		printed_chars = print_string(va_arg(*ap, char *), fmt);
	else if (fmt->type == 'd' || fmt->type == 'i')
		printed_chars = print_int(va_arg(*ap, int), fmt);
	else if (fmt->type == 'u')
		printed_chars = print_unsigned(va_arg(*ap, unsigned int), fmt);
	else if (fmt->type == 'x' || fmt->type == 'X')
		printed_chars = print_hex(va_arg(*ap, unsigned int), fmt);
	else if (fmt->type == 'p')
		printed_chars = print_pointer(va_arg(*ap, void *), fmt);
	else if (fmt->type == '%')
		printed_chars = print_percent(fmt);
	return (printed_chars);
}
