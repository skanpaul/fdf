/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_xyz_table.c                                     :+:      :+:    :+:   */
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
	t_p	*xyz_table;
	int	max_l;
	int	max_c;
	int	l;
	int	c;
	int z;

	max_l = info_table->max_l;
	max_c = info_table->max_c;
	l = 0;
	c = 0;

	xyz_table = (t_p *)malloc((max_l * max_c) * sizeof(t_p));
	l = 0;
	while (l < max_l)
	{
		c = 0;
		while (c < max_c)
		{
			z = z_table[l * max_l + c];
			xyz_table[l * max_l + c]
				= (t_p){.x = c, .y = l, .z = z};
			c++;
		}	
		l++;
	}
	return (xyz_table);
}
