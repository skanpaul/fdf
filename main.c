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
int main(void)
{
	t_data	data;

	/* INITIALISATION serveur -------------------------------------------- */
	if (initialisation(&data) == MLX_ERROR)
		return (MLX_ERROR);

	/* EXPERIMENTATION --------------------------------------------------- */
	draw_grid(100, &data, COLOR_BLUE);	
	
	/* GESTION des événements -------------------------------------------- */
	mlx_mouse_hook (data.win_ptr, mouse_action, (void *)&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_press, &data);	
	mlx_loop(data.mlx_ptr);		// FONCTION OBLIGATOIRE

	/* ------------------------------------------------------------------- */
	return 0;
}
