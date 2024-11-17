/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:04:57 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/17 09:04:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define F_DECIMAL 'd'
# define F_UNSIGNED 'u'
# define F_HEX_UPPER 'X'
# define F_HEX_LOWER 'x'
# define F_PERCENT '%'
# define F_CHAR 'c'
# define F_STRING 's'
# define F_POINTER 'p'
# define F_INT 'i'
# define HEX_BASE_L "0123456789abcdef"
# define HEX_BASE_U "0123456789ABCDEF"
# define DECIMAL_BASE "0123456789"

int	ft_printf(const char *format, ...);
int	print_based_on_format(const char format, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(unsigned long nbr, char *base);
int	ft_putnbr(long n);
int	ft_strlen(char *str);
int	ft_putptr(unsigned long ptr);

#endif
