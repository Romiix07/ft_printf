/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:18:09 by romain            #+#    #+#             */
/*   Updated: 2020/12/03 23:31:34 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	n1 = 0, n2;
	char *str = "shdsaoihd";

	n1 = ft_printf("%.p\n", str + 1);
	n2 = printf("%.p\n", str + 1);
	printf("n1 = %d, n2 = %d\n", n1, n2);
	return (0);
}
