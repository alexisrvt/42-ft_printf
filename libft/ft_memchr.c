/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:06:30 by alexisrvt         #+#    #+#             */
/*   Updated: 2026/05/21 13:56:10 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*su;

	su = s;
	while (0 < n)
	{
		if (*su == (char)c)
			return ((void *)su);
		su++;
		n--;
	}
	return (NULL);
}
