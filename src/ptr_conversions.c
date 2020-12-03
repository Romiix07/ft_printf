/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:49:40 by romain            #+#    #+#             */
/*   Updated: 2020/12/03 18:38:51 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_put_ptr(unsigned long long n, int counter)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16 && counter > 0)
		return (ft_put_ptr(n / 16, --counter) +
				ft_putchar_ret(hex[n % 16]));
	return (ft_putchar_ret(hex[n % 16]));
}

int			ptr_conversions(t_inf inf, va_list val)
{
	void				*ptr;
	unsigned long long	uptr;
	int					ret;

	ret = 0;
	ptr = va_arg(val, void *);
	uptr = (unsigned long long)ptr;
	ret += write(1, "0x", 2);
	ret += ft_put_ptr(uptr, inf.form_dot ? inf.prec_dot : 99);
	return (ret);
}
