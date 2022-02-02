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
// int main(int argc, char **argv)
int main(void)
{
	t_data	data;
	// t_file	file;
	// t_p		*table_point;
	// t_it	info_table;

	// file.name = "test";

	// if (argc != 2)
	// 	return (-1);
	// file.name = argv[1];

	// table_point = get_data_from_file(&file, &info_table);
	// if (table_point == NULL)
	// 	return (0);

	/* INITIALISATION serveur -------------------------------------------- */
	if (init_mlx(&data) == MLX_ERROR)
		return (MLX_ERROR);

	/* EXPERIMENTATION --------------------------------------------------- */
	draw_grid(100, &data, COLOR_BLUE);
	
	/* GESTION des événements -------------------------------------------- */
	mlx_mouse_hook (data.win_ptr, action_mouse, (void *)&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, action_key, &data);	
	mlx_loop(data.mlx_ptr);		// FONCTION OBLIGATOIRE

	/* ------------------------------------------------------------------- */
	return 0;
}
