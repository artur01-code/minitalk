/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_xup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:55:13 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/14 09:04:45 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_xup(va_list *args)
{
	unsigned int	nbr;
	int				counter;

	nbr = va_arg(*args, unsigned int);
	counter = ft_printhex(nbr, 'X');
	return (counter);
}
