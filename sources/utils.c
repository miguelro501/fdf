/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:22:54 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/06 21:56:24 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	terminate_fdf(void)
{
	free_maps();
	if (img()->mlx_img)
		mlx_destroy_image(data()->mlx, img()->mlx_img);
	if (data()->win)
		mlx_destroy_window(data()->mlx, data()->win);
	if (data()->mlx)
		mlx_loop_end(data()->mlx);
	if (data()->mlx)
	{
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	exit(0);
}

int	fdf_atoi(char *str, int y, int x, int i)
{
	int		neg;
	int		value;
	char	**color_value;

	neg = 1;
	value = 0;
	if (str[++i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		value = 10 * value + (str[i++] - '0');
	if (str[i] == ',')
	{
		color_value = ft_split(str, ',');
		map()->map[y][x].color = hex_to_int(color_value[1]);
		free_arr(color_value);
	}
	else
		map()->map[y][x].color = 0xFFFFFF;
	return (value * neg);
}

int	hex_to_int(char *hex_string)
{
	int	base;
	int	decimal;
	int	i;

	i = ft_strlen(hex_string);
	base = 1;
	decimal = 0;
	while (--i >= 0)
	{
		if (hex_string[i] >= '0' && hex_string[i] <= '9')
			decimal += (hex_string[i] - 48) * base;
		else if (hex_string[i] >= 'a' && hex_string[i] <= 'f')
			decimal += (hex_string[i] - 87) * base;
		else if (hex_string[i] >= 'A' && hex_string[i] <= 'F')
			decimal += (hex_string[i] - 55) * base;
		base *= 16;
	}
	return (decimal);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	error(char *str)
{
	ft_printf("%s\n", str);
	terminate_fdf();
}
