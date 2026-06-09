/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:48:14 by arivet            #+#    #+#             */
/*   Updated: 2026/06/09 16:50:52 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printper(t_format *fmt)
{
	int	pad;
	int	printed;

	pad = 0;
	printed = 0;
	if (fmt->width > 1)
		pad = fmt->width - 1;
	if (fmt->minus == 0 && pad > 0)
		printed += ft_printpad(' ', pad);
	printed += write(1, "%", 1);
	if (fmt->minus == 1 && pad > 0)
		printed += ft_printpad(' ', pad);
	return (printed);
}
