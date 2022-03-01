/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:22:04 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/13 12:25:03 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_cases(char c, va_list *args, int counter);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*ptf;
	int		counter;
	int		index;

	ptf = (char *) format;
	counter = 0;
	index = 0;
	va_start(args, format);
	while (ptf[index])
	{
		if (ptf[index] != '%')
		{
			ft_putchar_fd(ptf[index], 1);
			index++;
			counter++;
		}
		else
		{
			counter = check_cases(ptf[index + 1], &args, counter);
			index += 2;
		}
	}
	va_end(args);
	return (counter);
}

int	check_cases(char c, va_list *args, int counter)
{
	if (c == 'c')
		counter += case_c(args);
	else if (c == 's')
		counter += case_s(args);
	else if (c == '%')
		counter += case_pro();
	else if (c == 'd' || c == 'i')
		counter += case_d(args);
	else if (c == 'u')
		counter += case_u(args);
	else if (c == 'p')
		counter += case_p(args);
	else if (c == 'x')
		counter += case_x(args);
	else if (c == 'X')
		counter += case_xup(args);
	return (counter);
}
