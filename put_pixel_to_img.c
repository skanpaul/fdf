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
void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if ((x < 0) || (x > (W_WIDTH - 1)) || (y < 0) || (y > (W_HEIGHT - 1)))
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
