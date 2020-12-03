/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:18:09 by romain            #+#    #+#             */
/*   Updated: 2020/12/03 18:27:08 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	n1 = 0, n2;
	char *str = "shdsaoihd";

<<<<<<< Updated upstream
	n1 = ft_printf("%-5%\n");
	n2 = printf("%-5%\n");
=======
	n1 = ft_printf("%.*p\n", -3, str);
	n2 = printf("%.*p\n", -3, str);
>>>>>>> Stashed changes
	printf("n1 = %d, n2 = %d\n", n1, n2);
	return (0);
}
