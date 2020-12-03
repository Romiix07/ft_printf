/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:49:40 by romain            #+#    #+#             */
/*   Updated: 2020/12/03 19:13:18 by romain           ###   ########.fr       */
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

static int	get_ptr_length(unsigned long long n, t_inf inf)
{
	int	size;

	size = 2;
	while (n > 0)
	{
		n /= 16;
		++size;
	}
	if (inf.form_dot && size > inf.prec_dot)
		return (inf.prec_dot);
	return (size);
}

int			ptr_conversions(t_inf inf, va_list val)
{
	void				*ptr;
	unsigned long long	uptr;
	int					ret;
	int					length;

	ret = 0;
	ptr = va_arg(val, void *);
	uptr = (unsigned long long)ptr;
	length = get_ptr_length(uptr, inf);
	if (inf.form_nb && inf.prec_nb > 0)
		while (inf.prec_nb-- > length)
			ret += write(1, " ", 1);
	ret += write(1, "0x", 2);
	ret += ft_put_ptr(uptr, inf.form_dot ? inf.prec_dot - 2 : 99);
	/*	if (inf.from_nb && inf.prec_nb > 0)
		while (inf.prec_nb-- > lenght)
		ret += write(1, " ", 1);*/
	return (ret);
}
