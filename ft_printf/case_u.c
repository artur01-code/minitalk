/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:43:42 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/09 10:49:50 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_u(va_list *args)
{
	unsigned int	d;
	char			*str;

	d = va_arg(*args, unsigned int);
	str = ft_unsigneditoa(d);
	ft_putstr_fd(str, 1);
	d = ft_strlen(str);
	free(str);
	return (d);
}
