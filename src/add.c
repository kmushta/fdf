/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:41:35 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:41:37 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(t_float x, t_float y, t_float z)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		malloc_error();
	point->x = x;
	point->y = y;
	point->z = z;
	point->hidden = 0;
	return (point);
}

int		gradient(t_float pos, t_mlx *mlx)
{
	unsigned char	rgb[3];

	if (mlx->color)
		return (mlx->color);
	*rgb = 0;
	*(rgb + 1) = 255 * cos(pos);
	*(rgb + 2) = 0;
	if (pos < 0.0)
		*(rgb + 2) = 255 * sin(-pos);
	else
		*rgb = 255 * sin(pos);
	return ((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

t_mlx	*rev_line2(t_mlx *mlx)
{
	t_point	*point;

	point = mlx->line->p0;
	mlx->line->p0 = mlx->line->p1;
	mlx->line->p1 = point;
	return (mlx);
}

t_mlx	*new_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		malloc_error();
	if (!(mlx->cam = (t_cam *)malloc(sizeof(t_cam))))
		malloc_error();
	if (!(mlx->line = (t_line *)malloc(sizeof(t_line))))
		malloc_error();
	if (!(mlx->point = (t_point *)malloc(sizeof(t_point))))
		malloc_error();
	mlx->u = INT_MIN;
	mlx->d = INT_MAX;
	mlx->cam->ang_x = M_PI / 4;
	mlx->cam->ang_y = 0;
	mlx->cam->ang_z = M_PI / 4;
	mlx->cam->zoom = 5.0;
	mlx->cam->proj = 1;
	mlx->z = 0.1;
	mlx->color = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RES_W, RES_H, "fdf");
	mlx->img = new_image(mlx);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	return (mlx);
}
