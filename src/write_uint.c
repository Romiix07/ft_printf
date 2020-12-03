/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:40:55 by romain            #+#    #+#             */
/*   Updated: 2020/12/01 23:41:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_put_uint_base(unsigned int n, int base, char conv)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (conv == 'X' || conv == 'x')
		base = 16;
	else if (conv == 'o')
		base = 8;
	if (n >= (unsigned int)base)
	{
		return (ft_put_uint_base(n / base, base, conv) +
				ft_putchar_ret(n % base > 9 && conv == 'X' ?
							hex[n % base] - 32 : hex[n % base]));
	}
	return (ft_putchar_ret(n % base > 9 && conv == 'X' ?
						hex[n % base] - 32 : hex[n % base]));
}
