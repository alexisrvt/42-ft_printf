/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:32:13 by arvt              #+#    #+#             */
/*   Updated: 2026/06/06 19:44:02 by arivet           ###   ########.fr       */
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
void	init_format(t_format *fmt);
void	parse_format(const char *str, int *i, t_format *fmt);
int		dispatch_conversion(t_format *fmt, va_list *ap);
int		print_padding(char c, int n);
int		print_char(int c, t_format *fmt);

#endif
