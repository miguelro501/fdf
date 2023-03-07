/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:51:52 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/06 23:37:38 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gen_char_arr(int fd, int height)
{
	char	*line;
	void	*buff;
	int		bufi;

	line = get_next_line(fd);
	if (height == 0)
	{
		bufi = cont_words(line, ' ');
		map()->width = bufi;
	}
	if (line)
		gen_char_arr(fd, height + 1);
	else
	{
		buff = ft_calloc(sizeof(char *), (height + 1));
		map()->array = buff;
		map()->height = height;
	}
	if (map()->array)
		map()->array[height] = line;
}

void	gen_map(void)
{
	char	**split_result;
	void	*buff;

	buff = ft_calloc(sizeof(t_point *), map()->height);
	map()->map = buff;
	if (!map()->map)
		error("Error in memory allocation");
	split_result = ft_split(map()->array[0], ' ');
	map()->z_min = ft_atoi(split_result[0]);
	map()->z_max = map()->z_min;
	free_arr(split_result);
	fill_map(-1, -1);
}

void	fill_map_aux(int y, int x, char **line)
{
	int	value;

	while (++x < map()->width)
	{
		value = fdf_atoi(line[x], y, x, -1);
		if (value < map()->z_min)
			map()->z_min = value;
		else if (value > map()->z_max)
			map()->z_max = value;
		map()->map[y][x].z = value;
		map()->map[y][x].x = x * map()->space + WIN_WIDTH / 2 - map()->width
		/ 2;
		map()->map[y][x].y = y * map()->space + WIN_HEIGHT / 2
		- map()->height / 2;
	}
}

void	fill_map(int y, int x)
{
	char	**line;
	void	*buff;

	while (++y < map()->height)
	{
		x = -1;
		line = ft_split(map()->array[y], ' ');
		free(map()->map[y]);
		buff = ft_calloc(sizeof(t_point), map()->width);
		map()->map[y] = buff;
		if (!map()->map[y] || !line)
		{
			free_arr(line);
			terminate_fdf();
		}
		fill_map_aux(y, x, line);
		free_arr(line);
	}
	grid_to_iso();
}

void	free_maps(void)
{
	int	i;

	i = -1;
	while (++i < map()->height)
	{
		free(map()->array[i]);
		free(map()->map[i]);
	}
	free(map()->array);
	free(map()->map);
}
