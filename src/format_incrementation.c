/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_incrementation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:35:32 by romain            #+#    #+#             */
/*   Updated: 2020/12/07 23:06:02 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (s[i + 1] == '0' && s[i + 2] == '*')
		i += 2;
	else if (s[i + 1] == '*')
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
