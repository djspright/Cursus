/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:34:54 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/08 21:58:45 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	printf("--Basic test--\n");
	ret1 = ft_printf("Hello %s!\n", "42Tokyo");
	ret2 = printf("Hello, %s!\n", "42Tokyo");
	printf("Return value: ft_printf=%d, printf=%d\n", ret1, ret2);
	printf("--Test 'c'--\n");
	ret1 = ft_printf("%c\n", 'K');
	ret2 = printf("%c\n", 'K');
	printf("Return value: ft_printf=%d, printf=%d\n", ret1, ret2);
	return (0);
}
