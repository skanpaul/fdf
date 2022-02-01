/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_deform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:46:23 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 17:46:25 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
t_p *trans_deform(t_p *t, int size_l, int size_c, t_p i, t_p j, t_p k)
{
	int l;
	int c;
	t_p *deform;

	deform =(t_p *)malloc((size_l * size_c) * sizeof(t_p));

	l = 0;
	while (l < size_l)
	{
		c = 0;
		while (c < size_c)
		{
			deform[l * size_l + c].x = 
					t[l * size_l + c].x * i.x
				+ 	t[l * size_l + c].y * j.x
				+ 	t[l * size_l + c].z * k.x;
			deform[l * size_l + c].y = 
					t[l * size_l + c].x * i.y
				+ 	t[l * size_l + c].y * j.y
				+ 	t[l * size_l + c].z * k.y;
			c++;
		}	
		l++;
	}

	return (deform);
}
