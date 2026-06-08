/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:32:58 by arivet            #+#    #+#             */
/*   Updated: 2026/06/06 19:50:43 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c, t_format *fmt)
{
	int	printed;

	printed = 0;
	if (fmt->minus == 1)
	{
		printed += write(1, &c, 1);
		if (fmt->width > 1)
			printed += ft_printpad(' ', fmt->width - 1);
	}
	else
	{
		if (fmt->width > 1)
			printed += write(1, &c, 1);
	}
	return (printed);
}