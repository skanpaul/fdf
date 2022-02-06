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
static void	draw_line_right(int x, int y, t_p *xyz, t_data *data);
static void	draw_line_down(int x, int y, t_p *xyz, t_data *data);

/* ************************************************************************** */
void	draw(t_p *xyz, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->info_table.max_l)
	{
		x = 0;
		while (x < data->info_table.max_c)
		{
			draw_line_right(x, y, xyz, data);
			draw_line_down(x, y, xyz, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->ptr, 0, 0);
	return ;
}

/* ************************************************************************** */
static void	draw_line_right(int x, int y, t_p *xyz, t_data *data)
{
	t_p	start;
	t_p	p_right;	

	start = xyz[x + y * data->info_table.max_c];
	if (x != (data->info_table.max_c - 1))
	{
		p_right = xyz[(x + 1) + y * data->info_table.max_c];
		bresenham(start, p_right, data, COLOR_RED);
	}
}

/* ************************************************************************** */
static void	draw_line_down(int x, int y, t_p *xyz, t_data *data)
{	
	t_p	start;
	t_p	p_down;

	start = xyz[x + y * data->info_table.max_c];
	if (y < (data->info_table.max_l - 1))
	{
		p_down = xyz[x + (y + 1) * data->info_table.max_c];
		bresenham(start, p_down, data, COLOR_RED);
	}
}
