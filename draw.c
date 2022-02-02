/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:18:55 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 15:18:58 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void draw (t_p *xyz_table, int size_l, int size_c, t_data *data)
{
	int l;
	int c;
	t_p start;
	t_p p_droite;
	t_p p_bas;

	l = 0;
	while(l < size_l)
	{
		c = 0;
		while (c < size_c)
		{
			start = xyz_table[l * size_l + c];
			if(c != (size_c - 1))
			{
				p_droite = xyz_table[l * size_l + c + 1];
				bresenham(start, p_droite, data, COLOR_RED);
			}
			if(l < (size_l - 1))
			{
				p_bas = xyz_table[(l + 1) * size_l + c];
				bresenham(start, p_bas, data, COLOR_RED);
			}		
			c++;
		}
		l++;
	}	
	return ;
}
/* ************************************************************************** */
	// bresenham(table_2[0][0], table_2[0][1], data, COLOR_RED);
	// bresenham(table_2[0][0], table_2[1][0], data, COLOR_RED);
	// bresenham(table_2[1][0], table_2[1][1], data, COLOR_RED);
	// bresenham(table_2[1][1], table_2[0][1], data, COLOR_RED);


	// l = 0; c = 0;	start = xyz_table[l * size_l + c];
	// l = 0; c = 1;	end = xyz_table[l * size_l + c];
	// bresenham(start, end, data, COLOR_RED);
	
	// l = 0; c = 0;	start = xyz_table[l * size_l + c];
	// l = 1; c = 0;	end = xyz_table[l * size_l + c];
	// bresenham(start, end, data, COLOR_RED);
	
	// l = 1; c = 0;	start = xyz_table[l * size_l + c];
	// l = 1; c = 1;	end = xyz_table[l * size_l + c];
	// bresenham(start, end, data, COLOR_RED);
	
	// l = 0; c = 1;	start = xyz_table[l * size_l + c];
	// l = 1; c = 1;	end = xyz_table[l * size_l + c];
	// bresenham(start, end, data, COLOR_RED);
