/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:52:09 by romain            #+#    #+#             */
/*   Updated: 2020/12/03 17:44:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	select_func(va_list val, t_inf inf)
{
	int		i;
	char	*conversions;
	int		(*func[8])(t_inf, va_list);

	if (inf.conversion == '%')
	  return (percent_conversion(inf));
	i = -1;
	conversions = "cspdiuxX";
	func[0] = &char_conversions;
	func[1] = &char_conversions;
	func[2] = &ptr_conversions;
	func[3] = &int_conversions;
	func[4] = &int_conversions;
	func[5] = &uint_conversions;
	func[6] = &uint_conversions;
	func[7] = &uint_conversions;
	while (conversions[++i])
		if (inf.conversion == conversions[i])
			return ((*func[i])(inf, val));
	return (0);
}

static int	print_all(const char *s, va_list val)
{
	t_inf		infos;
	int			printed_chars;
	int			i;

	printed_chars = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			++i;
			infos = get_infos(&s[i], val);
			printed_chars += select_func(val, infos);
			while (s[i] && !is_conversion(s[i]))
				++i;
		}
		else
			printed_chars += write(1, &s[i], 1);
		if (!s[i])
			return (printed_chars);
	}
	return (printed_chars);
}

int			ft_printf(const char *s, ...)
{
	va_list	val;
	int		ret;

	va_start(val, s);
	ret = print_all(s, val);
	va_end(val);
	return (ret);
}
