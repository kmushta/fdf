/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:27:54 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:27:55 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalize_ang(t_mlx *mlx)
{
	if (mlx->cam->ang_x > M_PI)
		mlx->cam->ang_x = M_PI;
	else if (mlx->cam->ang_x < 0)
		mlx->cam->ang_x = 0;
	if (mlx->cam->ang_z > 2 * M_PI)
		mlx->cam->ang_z -= 2 * M_PI;
	else if (mlx->cam->ang_z < -2 * M_PI)
		mlx->cam->ang_z += 2 * M_PI;
}

void	projection(t_mlx *mlx, int i, int j)
{
	(mlx->map2)[i][j]->hidden = 0;
	if (mlx->cam->proj)
	{
		if ((mlx->map2)[i][j]->z < mlx->cam->dist)
		{
			(mlx->map2)[i][j]->x /= fabs(mlx->cam->dist - (mlx->map2)[i][j]->z)
				/ RES_W;
			(mlx->map2)[i][j]->y /= fabs(mlx->cam->dist - (mlx->map2)[i][j]->z)
				/ RES_W;
		}
		else
		{
			(mlx->map2)[i][j]->hidden = 1;
		}
	}
	(mlx->map2)[i][j]->x += RES_W / 2;
	(mlx->map2)[i][j]->y += RES_H / 2;
}
