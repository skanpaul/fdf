/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:07:13 by ski               #+#    #+#             */
/*   Updated: 2022/02/03 09:07:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void draw_grid(int size, t_data *data, int color)
{
	int x;
	int y;
	
	x = size;
	y = 0;
	while (x <= W_WIDTH)
	{
		while (y <= W_HEIGHT)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			y++;
		}
		y = 0;
		x += size;
	}

	y = size;
	x = 0;
	while (y <= W_HEIGHT)
	{
		while (x <= W_WIDTH)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			x++;
		}
		x = 0;
		y += size;
	}
}
