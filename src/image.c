/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:14:19 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:14:21 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_set_pixel(t_mlx *mlx, int x, int y, int c)
{
	*(int *)(mlx->img->ptr + ((x + y * RES_W) * mlx->img->bpp)) = c;
}

void	clear_image(t_mlx *mlx)
{
	int		i;

	i = RES_W * RES_H * mlx->img->bpp;
	while (--i)
		*(mlx->img->ptr + i) = 0;
	*(mlx->img->ptr) = 0;
}

t_image	*new_image(t_mlx *mlx)
{
	t_image	*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
		malloc_error();
	if (!(img->image = mlx_new_image(mlx->mlx, RES_W, RES_H)))
		malloc_error();
	img->ptr = mlx_get_data_addr(img->image, &(img->bpp), &(img->stride),
			&(img->endian));
	img->bpp = (img->bpp) >> 3;
	return (img);
}
