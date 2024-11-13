/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:43:53 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/13 01:43:53 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	return (write(1, "(null)", 6));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

__attribute__((unused))
static int	ft_putchar_tcase(int c) // TODO this func used to be for test
{
	static int	put_char_call_count = 0;

	put_char_call_count++;
	if (put_char_call_count == 4)
		return (-1);
	return (ft_putchar(c));
}
