/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:45:31 by miguelro          #+#    #+#             */
/*   Updated: 2022/11/21 20:46:03 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(t_ull n, char *base, t_ull baselen, char c)
{
	int	count;

	count = 0;
	if (c == 'p')
	{
		if (!n)
			return (ft_putstr("(nil)"));
		count = ft_putstr("0x");
		c = '0';
	}
	if (n >= baselen)
		count += ft_putnbr_base(n / baselen, base, baselen, c);
	return (write(1, &base[n % baselen], 1) + count);
}

int	ft_putnbr(long long nbr)
{
	int			count;

	count = 0;
	if (nbr < 0)
	{	
		nbr = -nbr;
		count += write(1, "-", 1);
	}
	return (count + ft_putnbr_base(nbr, DEC, 10, 'd'));
}
