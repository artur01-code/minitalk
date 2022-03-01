/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:46:21 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/13 09:08:43 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	createaddrstr(unsigned long int n, int counter)
{
	int	last_digit;

	if (counter == 0)
		counter += write(1, "0x", 2);
	if (n >= 16)
		counter = createaddrstr(n / 16, counter);
	last_digit = n % 16;
	counter += write(1, &"0123456789abcdef"[last_digit], 1);
	return (counter);
}

int	case_p(va_list *args)
{
	unsigned long int	n;
	int					counter;

	n = va_arg(*args, unsigned long int);
	counter = createaddrstr(n, counter = 0);
	return (counter);
}
