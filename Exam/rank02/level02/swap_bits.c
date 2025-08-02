/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:25:14 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/02 20:07:36 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	div;

	div = 0b10000000;
	while (div)
	{
		if (div & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		div >>= 1;
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main(void)
{
	print_bits(30);
	write(1, "\n", 1);
	print_bits(swap_bits(30));
}
