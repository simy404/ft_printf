/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:48:51 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/05 19:48:51 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

#include <stdio.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_putstr(char *str)
{
	if(str)
		return (write(1, str, ft_strlen(str)));
	return (write(1, "(null)", 6));
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int ft_putchar_tcase(int c) //TODO this func used to be for test
{
	static int put_char_call_count = 0;
	put_char_call_count++;
	if (put_char_call_count == 4)
		return -1;
	return ft_putchar(c);
}
int ft_putnbr_base(unsigned long nbr, char *base)
{
	int len;
	unsigned long base_len;
	base_len = ft_strlen(base);
	len = 0;
	if (nbr >= base_len)
		len = ft_putnbr_base(nbr / base_len, base);
	if (len == -1 || ft_putchar(base[nbr % base_len]) == -1)
			return (-1);
	return (len + 1);
}

int ft_putnbr(int n)
{
	int len;

	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len = ft_putnbr_base(-n, DECIMAL_BASE);
		if (len == -1)
			return (-1);
		return (len + 1);
	}
	return (ft_putnbr_base(n, DECIMAL_BASE));
}


