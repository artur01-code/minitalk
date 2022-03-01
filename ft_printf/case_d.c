/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:24:14 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/09 10:40:22 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_d(va_list *args)
{
	int		d;
	char	*str;

	d = va_arg(*args, int);
	str = ft_itoa(d);
	ft_putstr_fd(str, 1);
	d = ft_strlen(str);
	free(str);
	return (d);
}
