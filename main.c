/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:18:09 by romain            #+#    #+#             */
/*   Updated: 2020/12/04 02:03:41 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	n1 = 0, n2;
	char *str = "shdsaoihd";

	n1 = ft_printf("%0012.*X%00*.32i%-12d%-16.20%\n" ,25,3120340762u,-88,-387655089,12);
	n2 = printf("%0012.*X%00*.32i%-12d%-16.20%\n" ,25,3120340762u,-88,-387655089,12);
	printf("n1 = %d, n2 = %d\n", n1, n2);
	return (0);
}
