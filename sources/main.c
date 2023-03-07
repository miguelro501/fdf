/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:05:29 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/07 14:34:26 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	void	*buff;
	char	**line;

	if (ac != 2)
		error("Invalid number of parameters");
	data()->mlx = mlx_init();
	buff = mlx_new_window(data()->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	data()->win = buff;
	mlx_key_hook(data()->win, &handle_input, data());
	mlx_hook(data()->win, 17, 1L << 2, terminate_fdf, 0);
	line = ft_split(av[1], '.');
	if (!(ft_strlen(line[1]) == 3 && line[1][0] == 'f' && line[1][1] == 'd'
			&& line[1][2] == 'f'))
	{
		free_arr(line);
		error("File format invalid");
	}
	free_arr(line);
	data()->filename = av[1];
	map()->elevation = 1;
	map()->space = 20;
	map()->offset_x = 500;
	map()->offset_y = 400;
	render();
	mlx_loop(data()->mlx);
}
/* printf("h: %d\nw: %d\nz_max: %d\nz_min: %d\nSpace: %d\n", map()->height,
	map()->width, map()->z_max, map()->z_min, map()->space); */

void	render(void)
{
	void	*buff;

	free_maps();
	if (img()->mlx_img)
		mlx_destroy_image(data()->mlx, img()->mlx_img);
	buff = mlx_new_image(data()->mlx, WIN_WIDTH, WIN_HEIGHT);
	img()->mlx_img = buff;
	buff = mlx_get_data_addr(img()->mlx_img, &img()->bpp, &img()->line_len,
			&img()->endian);
	img()->addr = buff;
	gen_grid(data()->filename);
	print_grid();
	mlx_put_image_to_window(data()->mlx, data()->win, img()->mlx_img, 0, 0);
}
