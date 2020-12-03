/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:42:45 by romain            #+#    #+#             */
/*   Updated: 2020/12/03 16:43:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	get_uint_size(unsigned int n, unsigned int base, char conv)
{
	int	size;

	if (conv == 'X' || conv == 'x')
		base = 16;
	else if (conv == 'o')
		base = 8;
	size = 1;
	while (n >= base)
	{
		n /= base;
		++size;
	}
	return (size);
}
