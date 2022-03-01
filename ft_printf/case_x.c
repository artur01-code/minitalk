/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:32:01 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/14 09:04:41 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_x(va_list *args)
{
	unsigned int	nbr;
	int				counter;

	nbr = va_arg(*args, unsigned int);
	counter = ft_printhex(nbr, 'x');
	return (counter);
}
