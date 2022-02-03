/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_xyz_table.x                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:31:19 by ski               #+#    #+#             */
/*   Updated: 2022/02/02 17:31:21 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
t_p	*do_xyz_table(t_it *info_table, int *z_table)
{
	t_p	*xyz;
	int	max_l;
	int	max_c;
	int	y;
	int	x;
	int z;

	max_l = info_table->max_l;
	max_c = info_table->max_c;
	y = 0;
	x = 0;

	xyz = (t_p *)malloc((max_l * max_c) * sizeof(t_p));
	y = 0;
	while (y < max_l)
	{
		x = 0;
		while (x < max_c)
		{
			z = z_table[x + y * max_c];
			xyz[x + y * max_c]
				= (t_p){.x = x, .y = y, .z = z};
			x++;
		}	
		y++;
	}
	return (xyz);
}
