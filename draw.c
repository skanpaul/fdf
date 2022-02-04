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
// void draw (t_p *xyz_table, int max_l, int max_c, t_data *data)
void draw(t_p *xyz_table, t_data *data)
{
	int y;
	int x;
	t_p start;
	t_p p_droite;
	t_p p_bas;

	y = 0;
	while(y < data->info_table.max_l)
	{
		x = 0;
		while (x < data->info_table.max_c)
		{
			start = xyz_table[x + y * data->info_table.max_c];
			if(x != (data->info_table.max_c - 1))
			{
				p_droite = xyz_table[(x + 1) + y * data->info_table.max_c];
				bresenham(start, p_droite, data, COLOR_RED);
			}
			if(y < (data->info_table.max_l  - 1))
			{
				p_bas = xyz_table[x + (y + 1) * data->info_table.max_c];
				bresenham(start, p_bas, data, COLOR_RED);
			}		
			x++;
		}
		y++;
	}	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->ptr, 0, 0);
	return ;
}
/* ************************************************************************** */
