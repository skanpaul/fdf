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
void	put_pixel_to_img(t_img_data *img, t_point p, int color)
{
	char	*pixel_addr;

	pixel_addr = img->addr + (p.y * img->line_length + p.x * (img->bits_per_pixel / 8));

	*(unsigned int*)pixel_addr = color;
}
