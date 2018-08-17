/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:25:07 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:25:09 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calculate(t_mlx *mlx)
{
	int		i;
	int		j;

	normalize_ang(mlx);
	i = -1;
	while (++i < mlx->y)
	{
		j = -1;
		while (++j < mlx->x)
		{
			mlx->point->x = (mlx->map)[i][j]->x * mlx->cam->zoom;
			mlx->point->y = (mlx->map)[i][j]->y * mlx->cam->zoom;
			mlx->point->z = (mlx->map)[i][j]->z * mlx->cam->zoom * mlx->z;
			(mlx->map2)[i][j]->x = mlx->point->x
			* cos(mlx->cam->ang_z) + mlx->point->y * sin(mlx->cam->ang_z);
			(mlx->map2)[i][j]->y = mlx->point->y
			* cos(mlx->cam->ang_z) - mlx->point->x * sin(mlx->cam->ang_z);
			(mlx->map2)[i][j]->z = mlx->point->z
			* cos(mlx->cam->ang_x) + (mlx->map2)[i][j]->y
			* sin(mlx->cam->ang_x);
			(mlx->map2)[i][j]->y = (mlx->map2)[i][j]->y
			* cos(mlx->cam->ang_x) - mlx->point->z * sin(mlx->cam->ang_x);
			projection(mlx, i, j);
		}
	}
}

static void	clear(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < RES_H)
	{
		j = -1;
		while (++j < RES_W)
			(mlx->zbuff)[i][j] = (t_float)INT_MIN;
	}
	clear_image(mlx);
}

static void	render(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->y)
	{
		j = -1;
		while (++j < mlx->x)
		{
			if (i > 0)
			{
				mlx->line->p0 = (mlx->map2)[i][j];
				mlx->line->p1 = (mlx->map2)[i - 1][j];
				if (!mlx->line->p0->hidden && !mlx->line->p1->hidden)
					draw_line(mlx);
			}
			if (j > 0)
			{
				mlx->line->p0 = (mlx->map2)[i][j];
				mlx->line->p1 = (mlx->map2)[i][j - 1];
				if (!mlx->line->p0->hidden && !mlx->line->p1->hidden)
					draw_line(mlx);
			}
		}
	}
}

void		draw(t_mlx *mlx)
{
	calculate(mlx);
	clear(mlx);
	render(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->image, 0, 0);
}
