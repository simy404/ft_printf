/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:03:56 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/17 09:04:01 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_based_on_format(const char format, va_list args)
{
	if (format == F_CHAR)
		return (ft_putchar(va_arg(args, int)));
	else if (format == F_STRING)
		return (ft_putstr(va_arg(args, char *)));
	else if (format == F_DECIMAL || format == F_INT)
		return (ft_putnbr(va_arg(args, int)));
	else if (format == F_UNSIGNED)
		return (ft_putnbr_base(va_arg(args, unsigned int), HEX_BASE_U, 10));
	else if (format == F_HEX_LOWER)
		return (ft_putnbr_base(va_arg(args, unsigned int), HEX_BASE_L, 16));
	else if (format == F_HEX_UPPER)
		return (ft_putnbr_base(va_arg(args, unsigned int), HEX_BASE_U, 16));
	else if (format == F_POINTER)
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (format == F_PERCENT)
		return ((ft_putchar(F_PERCENT)));
	else
		return (0);
}
