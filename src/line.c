/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:26:43 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:26:44 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_on(int x, int y)
{
	return (x > -1 && x < RES_W && y > -1 && y < RES_H);
}

static void	init_t(int *tab, t_float *t, t_mlx *mlx, int mode)
{
	tab[0] = mlx->line->p1->x - mlx->line->p0->x;
	tab[1] = mlx->line->p1->y - mlx->line->p0->y;
	tab[2] = 1;
	if (!mode && tab[1] < 0 && (tab[2] = -1))
		tab[1] = -tab[1];
	else if (mode && tab[0] < 0 && (tab[2] = -1))
		tab[0] = -tab[0];
	if (!mode)
	{
		tab[3] = 2 * tab[1] - tab[0];
		tab[4] = mlx->line->p0->y;
		tab[5] = mlx->line->p0->x;
	}
	else
	{
		tab[3] = 2 * tab[0] - tab[1];
		tab[4] = mlx->line->p0->x;
		tab[5] = mlx->line->p0->y;
	}
	t[0] = mlx->line->p0->c;
	t[2] = mlx->line->p0->z;
}

static void	draw_line_low(t_mlx *mlx)
{
	int		tab[6];
	t_float	t[4];

	init_t(tab, t, mlx, 0);
	t[1] = 1.0 * (mlx->line->p1->c - mlx->line->p0->c)
		/ (mlx->line->p1->x - mlx->line->p0->x);
	t[3] = 1.0 * (mlx->line->p1->z - mlx->line->p0->z)
		/ (mlx->line->p1->x - mlx->line->p0->x);
	while (tab[5] <= mlx->line->p1->x)
	{
		if (is_on(tab[5], tab[4]) && (mlx->zbuff)[tab[4]][tab[5]] <= t[2])
		{
			image_set_pixel(mlx, tab[5], tab[4], gradient(t[0], mlx));
			(mlx->zbuff)[tab[4]][tab[5]] = t[2];
		}
		if (tab[3] > 0)
		{
			tab[4] = tab[4] + tab[2];
			tab[3] = tab[3] - 2 * tab[0];
		}
		tab[3] = tab[3] + 2 * tab[1];
		tab[5]++;
		t[0] += t[1];
		t[2] += t[3];
	}
}

static void	draw_line_high(t_mlx *mlx)
{
	int		tab[6];
	t_float	t[4];

	init_t(tab, t, mlx, 1);
	t[1] = 1.0 * (mlx->line->p1->c - mlx->line->p0->c)
		/ (mlx->line->p1->y - mlx->line->p0->y);
	t[3] = 1.0 * (mlx->line->p1->z - mlx->line->p0->z)
		/ (mlx->line->p1->y - mlx->line->p0->y);
	while (tab[5] <= mlx->line->p1->y)
	{
		if (is_on(tab[4], tab[5]) && (mlx->zbuff)[tab[5]][tab[4]] <= t[2])
		{
			image_set_pixel(mlx, tab[4], tab[5], gradient(t[0], mlx));
			(mlx->zbuff)[tab[5]][tab[4]] = t[2];
		}
		if (tab[3] > 0)
		{
			tab[4] = tab[4] + tab[2];
			tab[3] = tab[3] - 2 * tab[1];
		}
		tab[3] = tab[3] + 2 * tab[0];
		tab[5]++;
		t[0] += t[1];
		t[2] += t[3];
	}
}

void		draw_line(t_mlx *mlx)
{
	if (abs((int)mlx->line->p1->y - (int)mlx->line->p0->y) <
		abs((int)mlx->line->p1->x - (int)mlx->line->p0->x))
	{
		if (mlx->line->p0->x > mlx->line->p1->x)
			draw_line_low(rev_line2(mlx));
		else
			draw_line_low(mlx);
	}
	else
	{
		if (mlx->line->p0->y > mlx->line->p1->y)
			draw_line_high(rev_line2(mlx));
		else
			draw_line_high(mlx);
	}
}
