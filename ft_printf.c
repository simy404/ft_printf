/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 07:49:12 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/03 15:34:38 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	int total_len;
	int len_printed;

	total_len = 0;
	va_start(args, format);
	while(*format)
	{
		if(*format == F_PERCENT && is_specifier(*(format + 1)))
		{
			len_printed = print_based_on_format(*(++format), args);
			if (len_printed == -1)
				return (-1);
			total_len += len_printed;
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			total_len++;
		}
		format++;
	}
	va_end(args);
	return (total_len);
}

