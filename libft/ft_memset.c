/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:34:01 by alexisrvt         #+#    #+#             */
/*   Updated: 2026/05/27 13:20:10 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*su;

	su = (unsigned char *)s;
	while (0 < n)
	{
		*su = (unsigned char)c;
		su++;
		n--;
	}
	return (s);
}
