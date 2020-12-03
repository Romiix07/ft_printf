/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:49:40 by romain            #+#    #+#             */
/*   Updated: 2020/11/30 22:08:40 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ptr_conversions(t_inf inf, va_list val)
{
	void				*ptr;
	unsigned long long	uptr;
	int					ret;

	ret = 0;
	ptr = va_arg(val, void *);
	uptr = (unsigned long long)ptr;
	inf.conversion = 'x';
	ret += ft_put_uint_base(uptr, 16, inf.conversion);
	return (ret);
}
