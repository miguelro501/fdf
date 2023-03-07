/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:09:36 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/07 14:39:23 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int keysym)
{
	if (keysym == KEY_Q && map()->space < 50)
	{
		map()->space += 5;
		render();
	}
	if (keysym == KEY_E && map()->space > 5)
	{
		map()->space -= 5;
		render();
	}
}

void	translate(int keysym)
{
	if (keysym == KEY_W && map()->offset_y < WIN_HEIGHT / 2)
	{
		map()->offset_y += 50;
		render();
	}
	if (keysym == KEY_S && map()->offset_y > 0)
	{
		map()->offset_y -= 50;
		render();
	}
	if (keysym == KEY_A && map()->offset_x > 0)
	{
		map()->offset_x -= 50;
		render();
	}
	if (keysym == KEY_D && map()->offset_x < WIN_WIDTH / 2)
	{
		map()->offset_x += 50;
		render();
	}
}

void	elevate(int keysym)
{
	if (keysym == KEY_PLUS && map()->elevation < 10)
	{
		map()->elevation++;
		render();
	}
	if (keysym == KEY_MINUS && map()->elevation > 1)
	{
		map()->elevation--;
		render();
	}
}

int	handle_input(int keysym)
{
	if (keysym == KEY_PLUS || KEY_MINUS)
		elevate(keysym);
	if (keysym == KEY_Q || KEY_E)
		zoom(keysym);
	if (keysym == KEY_W || keysym == KEY_A || keysym == KEY_S
		|| keysym == KEY_D)
		translate(keysym);
	if (keysym == KEY_ESCAPE)
		terminate_fdf();
	return (0);
}

void	limit(void)
{
	if (!limits())
	{
		if (map()->space > 5)
		{
			map()->space -= 5;
			fill_map(-1, -1);
		}
		else
		{
			map()->elevation = 1;
			map()->space = 20;
			map()->offset_x = 500;
			map()->offset_y = 400;
		}
	}
}
//printf("key: %d\n", keysym);
