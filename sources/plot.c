/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:55:27 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/06 16:36:45 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpixel(int x, int y, int color)
{
	char	*dst;

	if (0 <= x && x <= WIN_WIDTH && 0 <= y && y <= WIN_HEIGHT)
	{
		dst = img()->addr + (y * img()->line_len + x * (img()->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

t_plot	calculate_line(t_point *start, t_point *end)
{
	t_plot	line;

	if (end->x >= start->x)
	{
		line.dx = end->x - start->x;
		line.sx = 1;
	}
	else
	{
		line.dx = start->x - end->x;
		line.sx = -1;
	}
	if (end->y >= start->y)
	{
		line.dy = -(end->y - start->y);
		line.sy = 1;
	}
	else
	{
		line.dy = -(start->y - end->y);
		line.sy = -1;
	}
	line.po = line.dx + line.dy;
	return (line);
}

int	plotline2(t_plot *plot, int y, int po2)
{
	if (po2 < plot->dx)
	{
		plot->po += plot->dx;
		y += plot->sy;
	}
	return (y);
}

int	plotline3(t_plot *plot, int x, int po2)
{
	if (po2 > plot->dy)
	{
		plot->po += plot->dy;
		x += plot->sx;
	}
	return (x);
}

void	plotline(t_point *start, t_point *end)
{
	t_plot	plot;
	int		y;
	int		x;
	int		po2;

	x = start->x;
	y = start->y;
	plot = calculate_line(start, end);
	while (1)
	{
		putpixel(x, y, start->color);
		if (x == end->x && y == end->y)
			break ;
		po2 = 2 * plot.po;
		y = plotline2(&plot, y, po2);
		x = plotline3(&plot, x, po2);
	}
}
