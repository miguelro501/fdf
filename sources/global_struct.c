/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:08:30 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/06 15:24:43 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*img(void)
{
	static t_img	img;

	return (&img);
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_point	new_point(int x, int y, t_map map)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map.array[x][y];
	point.color = 0xFFFFFF;
	return (point);
}
