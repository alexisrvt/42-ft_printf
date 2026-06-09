/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:32:13 by arvt              #+#    #+#             */
/*   Updated: 2026/06/09 11:11:27 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		dot;
	int		precision;
	char	type;
}			t_format;

int		ft_printf(const char *format, ...);
void	ft_initform(t_format *fmt);
void	ft_parse(const char *str, int *i, t_format *fmt);
int		ft_dispatch(t_format *fmt, va_list *ap);
int		ft_putnbr_abs(long n);
int		ft_nbrlen(long n);
int		ft_printpad(char c, int n);
int		ft_printchar(int c, t_format *fmt);
int		ft_printstr(char *str, t_format *fmt);
int		ft_printint(int n, t_format *fmt);

#endif
