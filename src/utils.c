/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:29:01 by kmushta           #+#    #+#             */
/*   Updated: 2018/03/27 13:29:03 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		argv_len(char **argv)
{
	int		i;

	if (!argv)
		return (0);
	i = 0;
	while (*argv++)
		i++;
	return (i);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_max3(int x, int y, int z)
{
	if (x > y)
	{
		if (x > z)
			return (x);
		return (z);
	}
	if (y > z)
		return (y);
	return (z);
}
