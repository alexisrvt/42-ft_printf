/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:29:02 by alexisrvt         #+#    #+#             */
/*   Updated: 2026/05/27 13:35:00 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	n;

	n = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (n / nmemb != size)
		return (NULL);
	p = malloc(n);
	if (p)
		ft_bzero(p, n);
	return (p);
}
