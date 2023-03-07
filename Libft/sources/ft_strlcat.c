/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:18:19 by miguelro          #+#    #+#             */
/*   Updated: 2022/10/26 15:54:56 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	src_index;

	srclen = ft_strlen(src);
	dstlen = 0;
	src_index = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	while (src[src_index] != 0 && (dstlen + src_index + 1) < size)
	{
		dst[dstlen + src_index] = src[src_index];
		src_index++;
	}
	if (dstlen < size)
		dst[dstlen + src_index] = 0;
	return (dstlen + srclen);
}
