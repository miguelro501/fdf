/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:33:54 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/06 15:35:16 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += ft_check_form(*++format, arg);
			format++;
		}
		else
		{
			count += ft_putchr(*format);
			format++;
		}
	}
	va_end(arg);
	return (count);
}
