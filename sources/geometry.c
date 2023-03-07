/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:35:05 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/06 23:38:32 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grid_to_iso(void)
{
	int	x;
	int	y;
	int	wx;
	int	wy;

	y = -1;
	while (++y < map()->height)
	{
		x = -1;
		while (++x < map()->width)
		{
			wx = map()->map[y][x].x;
			wy = map()->map[y][x].y;
			map()->map[y][x].x = (wx - wy) * cos(0.523599) + map()->offset_x;
			map()->map[y][x].y = (wx + wy) * sin(0.523599) - map()->offset_y
			- map()->map[y][x].z * map()->elevation;
		}
	}
	limit();
}

void	gen_grid(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error while opening file");
	gen_char_arr(fd, 0);
	close(fd);
	gen_map();
}

void	print_grid(void)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map()->height - 1)
	{
		x = -1;
		while (++x < map()->width - 1)
		{
			plotline(&map()->map[y][x], &map()->map[y][x + 1]);
			plotline(&map()->map[y][x], &map()->map[y + 1][x]);
			plotline(&map()->map[map()->height - 1][x],
				&map()->map[map()->height - 1][x + 1]);
			plotline(&map()->map[y][map()->width - 1], &map()->map[y
				+ 1][map()->width - 1]);
		}
	}
}

int	limits2(int y, int x)
{
	if (!(0 <= map()->map[y][x].x && map()->map[y][x].x <= WIN_WIDTH))
		return (0);
	if (!(0 <= map()->map[y][x].y && map()->map[y][x].y <= WIN_HEIGHT))
		return (0);
	return (1);
}

int	limits(void)
{
	if (!(limits2(0, 0) && limits2(0, map()->width - 1)))
		return (0);
	if (!(limits2(map()->height - 1, 0) && limits2(map()->height - 1,
				map()->width - 1)))
		return (0);
	return (1);
}
