/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:35:53 by arivet            #+#    #+#             */
/*   Updated: 2026/05/27 15:22:05 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set);
int	ft_end(char const *s1, char const *set);
int	ft_char_is_set(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
	{
		dest = malloc(sizeof(char) * 1);
		dest[i] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (end - start + 2));
	if (dest == NULL)
		return (NULL);
	while (start <= end)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}

int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && ft_char_is_set(&s1[i], set))
	{
		if (!(ft_char_is_set(&s1[i], set)))
			return (i);
		i++;
	}
	return (i);
}

int	ft_end(char const *s1, char const *set)
{
	int	s1_end;

	s1_end = ft_strlen(s1) - 1;
	while (s1[s1_end] > 0 && ft_char_is_set(&s1[s1_end], set))
	{
		if (!(ft_char_is_set(&s1[s1_end], set)))
			return (s1_end);
		s1_end--;
	}
	return (s1_end);
}

int	ft_char_is_set(char const *s1, char const *set)
{
	while (*set != '\0')
	{
		if (*s1 == *set)
			return (1);
		set++;
	}
	return (0);
}
