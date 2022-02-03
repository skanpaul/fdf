/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.x                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:18:55 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 15:18:58 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void draw (t_p *xyz_table, int max_l, int max_c, t_data *data)
{
	int y;
	int x;
	t_p start;
	t_p p_droite;
	t_p p_bas;

	y = 0;
	while(y < max_l)
	{
		x = 0;
		while (x < max_c)
		{
			start = xyz_table[x + y * max_c];
			if(x != (max_c - 1))
			{
				p_droite = xyz_table[(x + 1) + y * max_c];
				bresenham(start, p_droite, data, COLOR_RED);
			}
			if(y < (max_l - 1))
			{
				p_bas = xyz_table[x + (y + 1) * max_c];
				bresenham(start, p_bas, data, COLOR_RED);
			}		
			x++;
		}
		y++;
	}	
	return ;
}
/* ************************************************************************** */
	// bresenham(table_2[0][0], table_2[0][1], data, COLOR_RED);
	// bresenham(table_2[0][0], table_2[1][0], data, COLOR_RED);
	// bresenham(table_2[1][0], table_2[1][1], data, COLOR_RED);
	// bresenham(table_2[1][1], table_2[0][1], data, COLOR_RED);


	// y = 0; x = 0;	start = xyz_table[x + y * max_c];
	// y = 0; x = 1;	end = xyz_table[x + y * max_c];
	// bresenham(start, end, data, COLOR_RED);
	
	// y = 0; x = 0;	start = xyz_table[x + y * max_c];
	// y = 1; x = 0;	end = xyz_table[x + y * max_c];
	// bresenham(start, end, data, COLOR_RED);
	
	// y = 1; x = 0;	start = xyz_table[x + y * max_c];
	// y = 1; x = 1;	end = xyz_table[x + y * max_c];
	// bresenham(start, end, data, COLOR_RED);
	
	// y = 0; x = 1;	start = xyz_table[x + y * max_c];
	// y = 1; x = 1;	end = xyz_table[x + y * max_c];
	// bresenham(start, end, data, COLOR_RED);
