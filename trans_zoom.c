/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:48:57 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 17:49:02 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
t_p *trans_zoom(t_p *table, int size_l, int size_c, t_p factor)
{
	int l;
	int c;
	t_p *zoom;

	zoom =(t_p *)malloc((size_l * size_c) * sizeof(t_p));

	l = 0;
	while (l < size_l)
	{
		c = 0;
		while (c < size_c)
		{
			zoom[l * size_l + c].x = table[l * size_l + c].x * factor.x;
			zoom[l * size_l + c].y = table[l * size_l + c].y * factor.y;
			zoom[l * size_l + c].z = table[l * size_l + c].z * factor.z;
			c++;
		}	
		l++;
	}

	return (zoom);
}

