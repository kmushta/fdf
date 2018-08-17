/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:31:53 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:31:54 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_map(t_mlx *mlx)
{
	int		i;
	int		j;
	int		dh;

	dh = mlx->u - mlx->d;
	i = -1;
	while (++i < mlx->y)
	{
		j = -1;
		while (++j < mlx->x)
		{
			if (dh)
				(mlx->map)[i][j]->c = M_PI * ((mlx->map)[i][j]->z
					- (t_float)mlx->d) / (t_float)dh - 0.5 * M_PI;
			else
				(mlx->map)[i][j]->c = 0;
			(mlx->map)[i][j]->x -= 0.5 * (mlx->x - 1);
			(mlx->map)[i][j]->y -= 0.5 * (mlx->y - 1);
			(mlx->map)[i][j]->z -= 0.5 * (mlx->u + mlx->d);
		}
	}
	mlx->cam->dist = RES_W * 1.4;
}

void	create_render(t_mlx *mlx)
{
	int		i;
	int		j;

	if (!(mlx->zbuff = (t_float **)malloc(sizeof(t_float *) * RES_H)))
		malloc_error();
	i = -1;
	while (++i < RES_H)
	{
		if (!((mlx->zbuff)[i] = (t_float *)malloc(sizeof(t_float) * RES_W)))
			malloc_error();
		j = -1;
		while (++j < RES_W)
			(mlx->zbuff)[i][j] = (t_float)INT_MIN;
	}
	mlx->cam->zoom = 0.7 * ft_min(RES_W / mlx->x, RES_H / mlx->y);
}

void	create_map2(t_mlx *mlx)
{
	int		i;
	int		j;

	if (!(mlx->map2 = (t_point ***)malloc(sizeof(t_point **) * mlx->y)))
		malloc_error();
	i = -1;
	while (++i < mlx->y)
	{
		if (!((mlx->map2)[i] = (t_point **)malloc(sizeof(t_point *) * mlx->x)))
			malloc_error();
		j = -1;
		while (++j < mlx->x)
		{
			(mlx->map2)[i][j] = new_point((mlx->map)[i][j]->x,
				(mlx->map)[i][j]->y, (mlx->map)[i][j]->z);
			(mlx->map2)[i][j]->c = (mlx->map)[i][j]->c;
		}
	}
	create_render(mlx);
}
