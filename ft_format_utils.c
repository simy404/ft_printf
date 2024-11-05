/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:58:57 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/05 13:58:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int is_specifier(char format)
{
	return (format == F_DECIMAL || format == F_UNSIGNED ||
			format == F_HEX_UPPER || format == F_HEX_LOWER ||
			format == F_PERCENT || format == F_CHAR ||
			format == F_STRING || format == F_POINTER);
}

int print_based_on_format(const char format, va_list args)
{
	if (format == F_CHAR)
		return (ft_putchar(va_arg(args, int)));
	else if (format == F_DECIMAL)
		return ft_putnbr(va_arg(args, int));
	else if (format == F_HEX_LOWER)
		return (ft_putnbr_base(va_arg(args, unsigned long long), HEX_BASE_L));
	else if (format == F_HEX_UPPER)
		return (ft_putnbr_base(va_arg(args, unsigned long long), HEX_BASE_U));
	else if (format == F_PERCENT)
		return ((ft_putchar(F_PERCENT)));
	else if (format == F_POINTER)
		return (ft_putstr("0x") + ft_putnbr_base(va_arg(args, unsigned long long), HEX_BASE_L));
	else if (format == F_STRING)
		return ft_putstr(va_arg(args, char *));
	else if (format == F_UNSIGNED)
		return (ft_putnbr_base(va_arg(args, unsigned int), DECIMAL_BASE));
	else
		return ((ft_putchar(format)));
}
