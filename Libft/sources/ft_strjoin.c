/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:38:32 by miguelro          #+#    #+#             */
/*   Updated: 2022/10/28 17:40:18 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*finstr;

	finstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!finstr)
		return (NULL);
	ft_strlcpy(finstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(finstr, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (finstr);
}
