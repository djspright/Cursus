/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:22:07 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/11 00:24:27 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int ret1;
	int ret2;


	printf("--Basic test--\n");
	ret1 = ft_printf("Hello %s!\n", "42Tokyo");
	ret2 = printf("Hello, %s!\n", "42Tokyo");
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	printf("--Test 'c'--\n");
	ret1 = ft_printf("Char: %c\n", 'K');
	ret2 = printf("Char: %c\n", 'K');
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	printf("--Test '%%'--\n");
	ret1 = ft_printf("Percent: %%\n");
	ret2 = printf("Percent: %%\n");
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	printf("--Test 'd' and 'i'--\n");
	ret1 = ft_printf("Decimal: %d, Integer: %i\n", 123, -456);
	ret2 = printf("Decimal: %d, Integer: %i\n", 123, -456);
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);
	ret1 = ft_printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
	ret2 = printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	printf("--Test 'u'--\n");
	ret1 = ft_printf("Unsigned: %u, Zero: %u\n", 4294967295U, 0);
	ret2 = printf("Unsigned: %u, Zero: %u\n", 4294967295U, 0);
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	printf("--Test 'x' and 'X'--\n");
	ret1 = ft_printf("Hex lower: %x, Hex upper: %X\n", 0xabcdef, 0x12345F);
	ret2 = printf("Hex lower: %x, Hex upper: %X\n", 0xabcdef, 0x12345F);
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);
	ret1 = ft_printf("Hex zero: %x, Hex UINT_MAX: %X\n", 0, 0xFFFFFFFF);
	ret2 = printf("Hex zero: %x, Hex UINT_MAX: %X\n", 0, 0xFFFFFFFF);
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	printf("--Test 'p'--\n");
	int num = 42;
	char *str_ptr = "Hello";
	void *null_ptr = NULL;
	ret1 = ft_printf("Pointer to int: %p, Pointer to str: %p, NULL pointer: %p\n", &num, str_ptr, null_ptr);
	ret2 = printf("Pointer to int: %p, Pointer to str: %p, NULL pointer: %p\n",
			&num, str_ptr, null_ptr);
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	printf("--Test mixed--\n");
	ret1 = ft_printf("String: [%s], Dec: [%d], Char: [%c], Hex: [%x], Pointer: [%p]\n", "Test", -123, 'Z', 255, &num);
	ret2 = printf("String: [%s], Dec: [%d], Char: [%c], Hex: [%x], Pointer: [%p]\n", "Test", -123, 'Z', 255, &num);
	printf("Return value: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// printf("--Test NULL format--\n");
	// ret1 = ft_printf(NULL);
	// printf("Return value for NULL format: ft_printf=%d\n", ret1);

	return (0);
}
