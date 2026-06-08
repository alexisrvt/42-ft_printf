/* ************************************************************************** */
/*																			*/
/*														:::      ::::::::   */
/*   parsing.c										  :+:      :+:    :+:   */
/*													+:+ +:+		 +:+     */
/*   By: arivet <arivet@student.42roma.it>		  +#+  +:+       +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/06/03 22:06:59 by arivet			#+#    #+#			 */
/*   Updated: 2026/06/03 22:15:48 by arivet		   ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parseflags(const char *str, int *i, t_format *fmt)
{
	while (str[*i] && ft_strchr("-0# +", str[*i]))
	{
		if (str[*i] == '-')
			fmt->minus = 1;
		else if (str[*i] == '0')
			fmt->zero = 1;
		else if (str[*i] == '#')
			fmt->hash = 1;
		else if (str[*i] == ' ')
			fmt->space = 1;
		else if (str[*i] == '+')
			fmt->plus = 1;
		(*i)++;
	}
}

static void	ft_parsewidth(const char *str, int *i, t_format *fmt)
{
	while (str[*i] && ft_isdigit(str[*i]))
	{
		fmt->width = (fmt->width * 10) + (str[*i] - '0');
		(*i)++;
	}
}

static void	ft_parsepreci(const char *str, int *i, t_format *fmt)
{
	if (str[*i] == '.')
	{
		fmt->dot = 1;
		(*i)++;
		while (str[*i] && ft_isdigit(str[*i]))
		{
			fmt->precision = (fmt->precision * 10) + (str[*i] - '0');
			(*i)++;
		}
	}
}

static void	ft_parsetype(const char *str, int *i, t_format *fmt)
{
	if (str[*i] && ft_strchr("cspdiuxX%", str[*i]))
	{
		fmt->type = str[*i];
		(*i)++;
	}
}

void	ft_parse(const char *str, int *i, t_format *fmt)
{
	ft_initform(fmt);
	ft_parseflags(str, i, fmt);
	ft_parsewidth(str, i, fmt);
	ft_parsepreci(str, i, fmt);
	ft_parsetype(str, i, fmt);
}

