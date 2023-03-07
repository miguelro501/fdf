/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:20:30 by miguelro          #+#    #+#             */
/*   Updated: 2022/11/11 15:15:06 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		i++;
	return (write(1, s, i));
}
