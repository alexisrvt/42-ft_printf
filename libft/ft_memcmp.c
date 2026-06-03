/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:25:23 by alexisrvt         #+#    #+#             */
/*   Updated: 2026/05/21 11:49:53 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*su1;
	const unsigned char	*su2;

	su1 = s1;
	su2 = s2;
	while (0 < n)
	{
		if (*su1 != *su2)
			return (*su1 - *su2);
		su1++;
		su2++;
		--n;
	}
	return (0);
}
