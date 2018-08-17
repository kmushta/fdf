/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:36:54 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/02 17:36:56 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define RES_W 1920
# define RES_H 1080
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# ifndef M_FIBO
#  define M_FIBO 1.61803399
# endif
# define COLOR_RED 16711680
# define COLOR_GREEN 65280
# define COLOR_BLUE 255
# define COLOR_WHITE 16777215
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_OPEN 33
# define KEY_CLOSE 30
# define KEY_G 5
# define KEY_H 4
# define KEY_R 15
# define KEY_M 46
# define KEY_B 11
# define KEY_P 35

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

typedef float		t_float;

typedef struct		s_point
{
	t_float			x;
	t_float			y;
	t_float			z;
	t_float			c;
	char			hidden;
}					t_point;

typedef struct		s_line
{
	struct s_point	*p0;
	struct s_point	*p1;
}					t_line;

typedef struct		s_cam
{
	t_float			pos_x;
	t_float			pos_y;
	t_float			pos_z;
	t_float			ang_x;
	t_float			ang_y;
	t_float			ang_z;
	t_float			zoom;
	t_float			dist;
	int				proj;
}					t_cam;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	struct s_point	***map;
	struct s_point	***map2;
	t_float			**zbuff;
	struct s_line	*line;
	struct s_cam	*cam;
	struct s_image	*img;
	int				x;
	int				y;
	int				u;
	int				d;
	int				color;
	t_float			z;
	struct s_point	*point;
}					t_mlx;

t_point				*new_point(t_float x, t_float y, t_float z);
int					gradient(t_float pos, t_mlx *mlx);
t_mlx				*rev_line2(t_mlx *mlx);
t_mlx				*new_mlx(void);
void				height_map(t_mlx *mlx);
void				create_render(t_mlx *mlx);
void				create_map2(t_mlx *mlx);
void				draw(t_mlx *mlx);
void				usage(char *filename);
void				cannot_open_file(void);
void				invalid_map(void);
void				malloc_error(void);
void				image_set_pixel(t_mlx *mlx, int x, int y, int c);
void				clear_image(t_mlx *mlx);
t_image				*new_image(t_mlx *mlx);
int					key_hook(int key, t_mlx *mlx);
void				draw_line(t_mlx *mlx);
void				print_man(void);
void				normalize_ang(t_mlx *mlx);
void				projection(t_mlx *mlx, int i, int j);
void				read_map(t_mlx *mlx, int fd);
int					argv_len(char **argv);
int					ft_min(int a, int b);
int					ft_max3(int x, int y, int z);

#endif
