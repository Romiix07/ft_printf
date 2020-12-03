/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:18:09 by romain            #+#    #+#             */
/*   Updated: 2020/12/01 23:37:23 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	n1 = 0, n2;
	char *str = NULL;

	n1 = ft_printf("%-9.1s\n", NULL);
	n2 = printf("%-9.1s\n", NULL);
	printf("n1 = %d, n2 = %d\n", n1, n2);
	return (0);
}
