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

#include <stdarg.h>
#include "stdio.h"
// int print_based_on_specifiers(const char *format, ...)
// {

// }

int	ft_printf(const char *format, ...)
{
	va_list args;
	// args->fp_offset;
	// args->gp_offset;
	// args->overflow_arg_area;
	// args->reg_save_area;

	va_start(args, format);
	printf("%p\n", args->reg_save_area);
	va_arg(args, int );
	printf("%p\n", args->reg_save_area);
	va_arg(args, int );
	printf("%p\n", &args);
	va_arg(args, int );

	return 0;
}

int main()
{
	ft_printf("asdf",15.12f , 2.1f , 3);
}
