/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:36:26 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 13:36:33 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int main(int argc, char **argv)
{
	t_data	data;
	t_img	img;

	if (argc != 2)
		return (-1);
	data.file.name = argv[1];

	/* INITIALISATION serveur -------------------------------------------- */
	if (init_mlx(&data) == MLX_ERROR)
		return (MLX_ERROR);
	/* INITIALISATION image ---------------------------------------------- */
	img.ptr = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp,
			&img.size_line, &img.endian);
	data.img = &img;

	/* EXPERIMENTATION --------------------------------------------------- */
	// draw_grid(100, &data, COLOR_BLUE);

	/* GESTION des événements -------------------------------------------- */
	mlx_mouse_hook(data.win_ptr, action_mouse, (void *)&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, action_key, &data);	
	mlx_loop(data.mlx_ptr);		// FONCTION OBLIGATOIRE
	/* ------------------------------------------------------------------- */
	return (0);
}
