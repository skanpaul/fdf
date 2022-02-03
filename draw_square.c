/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:14:27 by ski               #+#    #+#             */
/*   Updated: 2022/02/03 16:14:29 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	draw_square(t_data *data, int color)
{
	int x; //x
	int y; //y
	t_img *img;

	img = data->img;

	/* -------------------------------------------- */
	y = 0;	
	x = 0;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	x = 1;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	x = 2;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	/* -------------------------------------------- */
	y = 1;	
	x = 0;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	x = 1;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	x = 2;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	/* -------------------------------------------- */
	y = 2;	
	x = 0;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	x = 1;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	x = 2;	put_pixel_to_img(img, x, y, COLOR_GREEN);
	/* -------------------------------------------- */

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->ptr, 0, 0);

}

