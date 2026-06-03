/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:41:49 by alexisrvt         #+#    #+#             */
/*   Updated: 2026/05/21 14:28:45 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s1;
	size_t	len;

	len = ft_strlen(s) + 1;
	s1 = malloc(len);
	if (s1 == NULL)
		return (NULL);
	ft_memcpy(s1, s, len);
	return (s1);
}
