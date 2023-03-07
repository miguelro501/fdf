/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:17 by miguelro          #+#    #+#             */
/*   Updated: 2022/11/16 14:54:49 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_form(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchr(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_putnbr_base((va_arg(arg, long long)), HEXAL, 16, 'p'));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int), HEXAL, 16, 'x'));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int), HEXAU, 16, 'X'));
	if (c == '%')
		return (ft_putchr('%'));
	return (0);
}
