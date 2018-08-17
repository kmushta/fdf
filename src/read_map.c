/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:30:54 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:30:55 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	**unpack(char ***s, t_mlx *mlx)
{
	t_point	**map;
	int		i;
	char	**str;
	int		value;

	if (!(map = (t_point **)malloc(sizeof(t_point *) * (mlx->x))))
		malloc_error();
	i = -1;
	while (++i < mlx->x)
	{
		value = ft_atoi((*s)[i]);
		if (value > mlx->u)
			mlx->u = value;
		if (value < mlx->d)
			mlx->d = value;
		map[i] = new_point((t_float)i, (t_float)(mlx->y), (t_float)value);
	}
	str = *s;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(*s);
	return (map);
}

void			read_map(t_mlx *mlx, int fd)
{
	char	*line;
	char	**s;

	if (get_next_line(fd, &line) != 1)
		invalid_map();
	s = ft_strsplit(line, ' ');
	free(line);
	mlx->x = argv_len(s);
	mlx->y = 0;
	if (!(mlx->map = (t_point ***)malloc(sizeof(t_point **))))
		malloc_error();
	(mlx->map)[mlx->y] = unpack(&s, mlx);
	mlx->y += 1;
	while (get_next_line(fd, &line) == 1)
	{
		s = ft_strsplit(line, ' ');
		free(line);
		if (!mlx->x || mlx->x != argv_len(s))
			invalid_map();
		ft_realloc((void **)(&(mlx->map)), sizeof(t_point ***) * mlx->y,
			sizeof(t_point ***) * ((mlx->y) + 1));
		(mlx->map)[(mlx->y)++] = unpack(&s, mlx);
	}
	height_map(mlx);
	create_map2(mlx);
}
