/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majbdour <majbdour@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:17:24 by majbdour          #+#    #+#             */
/*   Updated: 2026/01/12 19:17:29 by majbdour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char type)
{
	char	*base;
	int		count;

	count = 0;
	if (type == 'x')
		base = "0123456789abcdef\0";
	else if (type == 'X')
		base = "0123456789ABCDEF\0";
	if (n >= 16)
		count += ft_puthex(n / 16, type);
	count += ft_putchar(base[n % 16]);
	return (count);
}
