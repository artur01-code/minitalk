/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:34:27 by jtomala           #+#    #+#             */
/*   Updated: 2021/11/25 11:52:29 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int arg)
{
	if ((arg >= 65 && arg <= 90) || (arg >= 97 && arg <= 122))
		return (1);
	else if (arg >= 48 && arg <= 57)
		return (1);
	else
		return (0);
}
