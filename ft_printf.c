/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:14:30 by arvt              #+#    #+#             */
/*   Updated: 2026/06/12 12:53:59 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_format	fmt;
	va_list		ap;
	int			i;
	int			printed;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			ft_parse(format, &i, &fmt);
			printed += ft_dispatch(&fmt, &ap);
		}
		else
			printed += write(1, &format[i++], 1);
	}
	va_end(ap);
	return (printed);
}
