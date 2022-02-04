/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:23:35 by ski               #+#    #+#             */
/*   Updated: 2022/01/23 15:23:37 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
// void	put_pixel_to_img(t_img *img, t_p p, int color)
// {
// 	char	*pixel_addr;

// 	pixel_addr = img->addr + (p.y * img->size_line + p.x * (img->bpp / 8));

// 	*(unsigned int*)pixel_addr = color;
// }

/* ************************************************************************** */
// void	put_pixel_to_img(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;

//     pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
// 	*(unsigned int *)pixel = color;
// }
/* ************************************************************************** */
void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	if ((x >= W_WIDTH) || (y >= W_HEIGHT)  )
		return;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
