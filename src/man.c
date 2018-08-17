/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:30:11 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:30:12 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_man(void)
{
	ft_printf("Use these keys to manipulate 3d-output:\n");
	ft_printf("W, S, A, D to rotate,\n");
	ft_printf("+, - to zoom in and zoom out,\n");
	ft_printf("R, G, B, H, M to change the color scheme,\n");
	ft_printf("[, ] to decrease or increase the scale height,\n");
	ft_printf("P to change projection type,\n");
	ft_printf("ESC to exit.\n");
}
