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
	return (write(1, str, ft_strlen(str)));
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int ft_putnbr_base(unsigned long long nbr, char *base)
{
	int len;
	unsigned long long base_len;

	base_len = ft_strlen(base);
	len = 0;
	if (nbr >= base_len)
	{
		len += ft_putnbr_base(nbr / base_len, base);
		len += ft_putchar(base[nbr % base_len]);
	}
	else
		len += ft_putchar(base[nbr]);
	return (len);
}

int ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr_base(-n, DECIMAL_BASE) + 1);
	}
	return (ft_putnbr_base(n, DECIMAL_BASE));
}


