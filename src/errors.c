/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:12:40 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:12:42 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(char *filename)
{
	printf("Usage: %s [map filename]\n", filename);
	exit(0);
}

void	cannot_open_file(void)
{
	ft_putstr_fd("Error: cannot open file or file doesn't exists\n", 2);
	exit(0);
}

void	invalid_map(void)
{
	ft_putstr_fd("Error: invalid map file\n", 2);
	exit(0);
}

void	malloc_error(void)
{
	ft_putstr_fd("Error: cannot allocate memory. Exit now!\n", 2);
	exit(0);
}
