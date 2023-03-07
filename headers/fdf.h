/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:21 by miguelro          #+#    #+#             */
/*   Updated: 2023/03/06 16:31:50 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define KEY_ESCAPE 65307
# define KEY_PLUS 43
# define KEY_MINUS 45
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define EXIT_BUTTON 33

typedef struct s_plot
{
	int		po;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
}			t_plot;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

typedef struct s_map
{
	int		height;
	int		width;
	char	**array;
	t_point	**map;
	int		z_max;
	int		z_min;
	int		space;
	int		elevation;
	int		offset_x;
	int		offset_y;
}			t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*filename;
}			t_data;

t_data		*data(void);
t_img		*img(void);
t_map		*map(void);
t_point		new_point(int x, int y, t_map map);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		plotline(t_point *start, t_point *end);
void		gen_grid(char *file);
void		putpixel(int x, int y, int color);
int			cont_words(const char *str, const char c);
void		print_grid(void);
void		grid_to_iso(void);
int			limits2(int y, int x);
int			limits(void);
int			terminate_fdf(void);
void		gen_char_arr(int fd, int height);
void		gen_map(void);
void		fill_map(int y, int x);
int			handle_input(int keysym);
void		render(void);
void		free_arr(char **arr);
void		error(char *str);
void		free_maps(void);
int			hex_to_int(char *hex_string);
int			fdf_atoi(char *str, int y, int x, int i);
void		limit(void);

#endif