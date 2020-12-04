/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_incrementation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:35:32 by romain            #+#    #+#             */
/*   Updated: 2020/12/04 02:03:06 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	dot_incr(const char *s, int i)
{
	if (s[i + 1] == '*')
		++i;
	else if (ft_isdigit(s[i + 1]))
		while (ft_isdigit(s[i + 1]))
			++i;
	return (i);
}

int	minus_incr(const char *s, int i)
{
	if (s[i + 1] == '*')
		++i;
	else if (ft_isdigit(s[i + 1]))
		while (ft_isdigit(s[i + 1]))
			++i;
	return (i);
}

int	zero_incr(const char *s, int i)
{
	if (s[i + 1] == '*')
		++i;
	else if (ft_isdigit(s[i + 1]) && s[i + 1] != '0')
		while (ft_isdigit(s[i + 1]))
			++i;
	return (i);
}

int	nb_incr(const char *s, int i)
{
	while (ft_isdigit(s[i + 1]))
		++i;
	return (i);
}