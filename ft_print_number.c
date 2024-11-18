/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:04:11 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/17 09:04:14 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base, unsigned long base_len)
{
	int	len;

	len = 0;
	if (nbr >= base_len)
		len = ft_putnbr_base(nbr / base_len, base, base_len);
	if (len == -1 || ft_putchar(base[nbr % base_len]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbr(long n)
{
	int	len;

	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len = ft_putnbr_base(-1 * n, HEX_BASE_U, 10);
		if (len == -1)
			return (-1);
		return (len + 1);
	}
	return (ft_putnbr_base(n, HEX_BASE_U, 10));
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len = ft_putnbr_base(ptr, HEX_BASE_L, 16);
	if (len == -1)
		return (-1);
	return (len + 2);
}
