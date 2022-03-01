/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:38:18 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/14 09:00:56 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		check_cases(char c, va_list *args, int counter);

int		ft_printf(const char *format, ...);

int		case_c(va_list *args);

int		case_s(va_list *args);

int		case_pro(void);

int		case_d(va_list *args);

int		case_u(va_list *args);

char	*ft_unsigneditoa(unsigned int nb);

int		case_p(va_list *args);

int		case_x(va_list *args);

int		case_xup(va_list *args);

int		ft_printhex(unsigned int nbr, const char format);

#endif