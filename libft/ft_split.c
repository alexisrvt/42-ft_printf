/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:03:27 by arivet            #+#    #+#             */
/*   Updated: 2026/05/27 13:44:08 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char const *s, char c);
char	**ft_strs_malloc(char **arr, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;

	j = 0;
	dest = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strs_malloc(dest, s, c);
	while (c == *s && *s)
		s++;
	while (*s != '\0')
	{
		i = 0;
		while (*s != c && *s != '\0')
			dest[j][i++] = *s++;
		dest[j][i] = '\0';
		j++;
		while (*s == c && *s != '\0')
			s++;
	}
	return (dest);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		i++;
		while (*s == c && *s)
			s++;
	}
	return (i);
}

char	**ft_strs_malloc(char **arr, char const *s, char c)
{
	int	size;

	while (*s == c && *s)
		s++;
	while (*s != '\0')
	{
		size = 0;
		while (*s != c && *s != '\0')
		{
			s++;
			size++;
		}
		*arr = malloc(sizeof(char) * (size + 1));
		arr++;
		while (*s == c && *s != '\0')
			s++;
	}
	*arr = NULL;
	return (arr);
}
