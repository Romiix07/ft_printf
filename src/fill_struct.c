/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:49:25 by romain            #+#    #+#             */
/*   Updated: 2020/12/03 22:20:36 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int				is_conversion(char c)
{
	int		i;
	char	*conversions;

	i = -1;
	conversions = "cspdiuxX%";
	while (conversions[++i])
		if (c == conversions[i])
			return (1);
	return (0);
}

static t_inf	fill_inf(t_inf inf, const char *s, va_list v)
{
	if (*s == '-' && *(s + 1) == '*')
	{
		inf.prec_nb = va_arg(v, int);
		inf.prec_nb *= inf.prec_nb > 0 ? -1 : 1;
	}
	if (*s == '0')
		inf.prec_zero = *(s + 1) == '*' ? va_arg(v, int) : ft_atoi(s + 1);
	if ((*s >= '1' && *s <= '9') || *s == '*' || (*s == '-' && *(s + 1) != '*'))
		inf.prec_nb = *s == '*' ? va_arg(v, int) : ft_atoi(s);
	if (*s == '.')
	{
		if (ft_isdigit(*(s + 1)))
			inf.prec_dot = ft_atoi(s + 1);
		else if (*(s + 1) == '*')
			inf.prec_dot = va_arg(v, int);
	}
	return (inf);
}

static t_inf	reset_infos(void)
{
	t_inf	inf;

	inf.conversion = 0;
	inf.prec_nb = 0;
	inf.prec_dot = 0;
	inf.prec_zero = 0;
	inf.form_nb = 0;
	inf.form_dot = 0;
	inf.form_zero = 0;
	return (inf);
}

t_inf			check_inf(t_inf inf)
{
	if (inf.form_dot && inf.prec_dot < 0)
		inf.form_dot = 0;
	if (inf.form_dot && inf.form_zero)
	{
		inf.form_zero = 0;
		inf.form_nb = 1;
		inf.prec_nb = inf.prec_zero;
	}
	return (inf);
}

t_inf			get_infos(const char *s, va_list val)
{
	t_inf		inf;
	int			i;

	inf = reset_infos();
	i = -1;
	while (s[++i] && !is_conversion(s[i]))
	{
		inf = fill_inf(inf, &s[i], val);
		if (s[i] == '0')
			inf.form_zero = 1;
		if (s[i] == '.')
			inf.form_dot = 1;
		if (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '*')
			inf.form_nb = 1;
		if ((ft_isdigit(s[i + 1]) || s[i + 1] == '*') &&
			!is_conversion(s[i + 1]) && (s[i] == '-' || s[i] == '.' || s[i] == '0'))
			++i;
		while (s[i] && s[i + 1] && ft_isdigit(s[i]) && ft_isdigit(s[i + 1]))
			++i;
	}
	inf.conversion = s[i];
	inf = check_inf(inf);
	return (inf);
}
