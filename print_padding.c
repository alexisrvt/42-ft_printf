/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:39:22 by arivet            #+#    #+#             */
/*   Updated: 2026/06/06 19:50:53 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(char c, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += write(1, &c, 1);
		n--;
	}
	return (count);
}
