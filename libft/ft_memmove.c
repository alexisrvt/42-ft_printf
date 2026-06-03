/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:46:20 by alexisrvt         #+#    #+#             */
/*   Updated: 2026/05/27 13:29:29 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (s < d && d < s + n)
	{
		d += n;
		s += n;
		while (0 < n)
		{
			*--d = *--s;
			n--;
		}
	}
	else
	{
		while (0 < n)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}
