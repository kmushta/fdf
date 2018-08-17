/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:40:41 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/02 15:40:42 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc != 2)
		usage(*(argv + 1));
	if ((fd = open(*(argv + 1), O_RDONLY)) == -1)
		cannot_open_file();
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		malloc_error();
	mlx = new_mlx();
	read_map(mlx, fd);
	draw(mlx);
	print_man();
	mlx_loop(mlx->mlx);
	close(fd);
	return (0);
}
