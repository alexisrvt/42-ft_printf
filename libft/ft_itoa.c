/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:54:03 by arivet            #+#    #+#             */
/*   Updated: 2026/05/27 13:44:42 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_into_str(char *str, long nb);
void	ft_str_reverse(char *str);

char	*ft_itoa(int n)
{
	char	str[14];
	char	*dest;
	int		i;
	long	nb;

	nb = n;
	i = 0;
	ft_int_into_str(str, nb);
	ft_str_reverse(str);
	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_int_into_str(char *str, long nb)
{
	int	i;
	int	sign;

	i = 0;
	sign = nb;
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		str[i++] = '0';
	while (nb > 0)
	{
		str[i++] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
}

void	ft_str_reverse(char *str)
{
	int		length;
	int		j;
	int		k;
	char	temp;

	length = ft_strlen(str);
	j = 0;
	k = length - 1;
	while (j < k)
	{
		temp = str[j];
		str[j] = str[k];
		str[k] = temp;
		j++;
		k--;
	}
}
