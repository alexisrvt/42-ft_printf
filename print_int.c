/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:05:30 by arivet            #+#    #+#             */
/*   Updated: 2026/06/08 16:58:55 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n, t_format *fmt)
{
	int	printed;

	printed = 0;
	if (n >= 0)
	{
		if (fmt->plus == 1)
			printed += write(1, "+", 1);
		else if (fmt->space == 1)
			printed += write(1, " ", 1);
	}
	else if (n < 0)
		printed += write (1, "-", 1);
}