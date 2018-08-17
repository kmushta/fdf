/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:15:35 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:15:36 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotation(int key, t_mlx *mlx)
{
	if (key == KEY_A)
	{
		(mlx->cam->ang_z) -= M_PI / 24;
		draw(mlx);
	}
	if (key == KEY_D)
	{
		(mlx->cam->ang_z) += M_PI / 24;
		draw(mlx);
	}
	if (key == KEY_S)
	{
		(mlx->cam->ang_x) -= M_PI / 24;
		draw(mlx);
	}
	if (key == KEY_W)
	{
		(mlx->cam->ang_x) += M_PI / 24;
		draw(mlx);
	}
}

static void	change_height(int key, t_mlx *mlx)
{
	if (key == KEY_OPEN)
	{
		(mlx->z) /= M_FIBO;
		draw(mlx);
	}
	if (key == KEY_CLOSE)
	{
		(mlx->z) *= M_FIBO;
		draw(mlx);
	}
}

static void	zooming(int key, t_mlx *mlx)
{
	if (key == KEY_PLUS)
	{
		(mlx->cam->zoom) *= M_FIBO;
		draw(mlx);
	}
	if (key == KEY_MINUS)
	{
		(mlx->cam->zoom) /= M_FIBO;
		draw(mlx);
	}
}

static void	change_color(int key, t_mlx *mlx)
{
	if (key == KEY_B)
	{
		(mlx->color) = COLOR_BLUE;
		draw(mlx);
	}
	if (key == KEY_G)
	{
		(mlx->color) = COLOR_GREEN;
		draw(mlx);
	}
	if (key == KEY_H)
	{
		(mlx->color) = COLOR_WHITE;
		draw(mlx);
	}
	if (key == KEY_M)
	{
		(mlx->color) = 0;
		draw(mlx);
	}
	if (key == KEY_R)
	{
		(mlx->color) = COLOR_RED;
		draw(mlx);
	}
}

int			key_hook(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	rotation(key, mlx);
	change_height(key, mlx);
	zooming(key, mlx);
	change_color(key, mlx);
	if (key == KEY_P)
	{
		if (mlx->cam->proj)
			mlx->cam->proj = 0;
		else
			mlx->cam->proj = 1;
		draw(mlx);
	}
	return (0);
}
