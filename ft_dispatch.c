/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:07:52 by arivet            #+#    #+#             */
/*   Updated: 2026/06/09 16:47:53 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(t_format *fmt, va_list *ap)
{
	int	printed_chars;

	printed_chars = 0;
	if (fmt->type == 'c')
		printed_chars = ft_printchar(va_arg(*ap, int), fmt);
	else if (fmt->type == 's')
		printed_chars = ft_printstr(va_arg(*ap, char *), fmt);
	else if (fmt->type == 'd' || fmt->type == 'i')
		printed_chars = ft_printint(va_arg(*ap, int), fmt);
	else if (fmt->type == 'u')
		printed_chars = ft_printunint(va_arg(*ap, unsigned int), fmt);
	else if (fmt->type == 'x' || fmt->type == 'X')
		printed_chars = ft_printhex(va_arg(*ap, unsigned int), fmt);
	else if (fmt->type == 'p')
		printed_chars = ft_printptr(va_arg(*ap, void *), fmt);
	else if (fmt->type == '%')
		printed_chars = ft_printper(fmt);
	return (printed_chars);
}
