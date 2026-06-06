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

void	parse_flags(const char *str, int *i, t_format *fmt);
void	parse_width(const char *str, int *i, t_format *fmt);
void	parse_precision(const char *str, int *i, t_format *fmt);
void	parse_type(const char *str, int *i, t_format *fmt);

void	parse_format(const char *str, int *i, t_format *fmt)
{
	init_format(fmt);
	parse_flags(str, i, fmt);
	parse_width(str, i, fmt);
	parse_precision(str, i, fmt);
	parse_type(str, i, fmt);
}

void	parse_flags(const char *str, int *i, t_format *fmt)
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

void	parse_width(const char *str, int *i, t_format *fmt)
{
	while (str[*i] && ft_isdigit(str[*i]))
	{
		fmt->width = (fmt->width * 10) + (str[*i] - '0');
		(*i)++;
	}
}

void	parse_precision(const char *str, int *i, t_format *fmt)
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

void	parse_type(const char *str, int *i, t_format *fmt)
{
	if (str[*i] && ft_strchr("cspdiuxX%", str[*i]))
	{
		fmt->type = str[*i];
		(*i)++;
	}
}
