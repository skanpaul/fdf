/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:13:23 by ski               #+#    #+#             */
/*   Updated: 2022/01/27 09:13:24 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
bool is_screen_overflow(int x, int y)
{
	if (x > W_WIDTH)
		return (true);

	if (y > W_HEIGHT)
		return (true);

	return (false);
}

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

/* ************************************************************************** */