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
// {
// 	t_data	data;
// 	t_img	img;

// 	if (argc != 2)
// 		return (-1);

// 	data.file.name = argv[1];
int main(void)
{
	t_data	data;
	t_img	img;

	data.coef = 1;
	data.alpha_z = 0;
	data.alpha_x = 0;
	data.alpha_y = 0;

	// data.file.name = "test_maps/texte";
	data.file.name = "test_maps/42.fdf";	
	// data.file.name = "test_maps/100-6.fdf"; 		// depasse peut etre gauche et droite
	// data.file.name = "test_maps/elem-fract.fdf";		// TRES LONG
	// data.file.name = "test_maps/julia.fdf";			// TRES LONG
	// data.file.name = "test_maps/mars.fdf";			// PROBLEME
	data.xyz = get_data_from_file(&(data.file), &(data.info_table));
	if (data.xyz  == NULL)
		return (0);
	
	/* INITIALISATION serveur -------------------------------------------- */
	if (init_mlx(&data) == MLX_ERROR)
		return (MLX_ERROR);

	/* INITIALISATION image ---------------------------------------------- */
	img.ptr = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp,
			&img.size_line, &img.endian);
	data.img = &img;

	/* INITIALISATION vecteur -------------------------------------------- */
	init_vector_unit_iso(&data);
	init_vector_zoom(&data, data.coef);
	init_vector_decal(&data);


	rendering(data.xyz, &data);

	/* GESTION des événements -------------------------------------------- */
	mlx_mouse_hook(data.win_ptr, action_mouse, (void *)&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, action_key, &data);	
	mlx_loop(data.mlx_ptr);		// FONCTION OBLIGATOIRE
	/* ------------------------------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
	// data.file.name = "test_maps/10-2.fdf";
	// data.file.name = "test_maps/10-70.fdf";		// depasse en haut
	// data.file.name = "test_maps/100-6.fdf"; 		// depasse peut etre gauche et droite
	// data.file.name = "test_maps/20-60.fdf";		// depasse en haut
	// data.file.name = "test_maps/42.fdf";
	// data.file.name = "test_maps/50-4.fdf";
	// data.file.name = "test_maps/basictest.fdf";
	// data.file.name = "test_maps/elem-col.fdf";
	// data.file.name = "test_maps/elem-fract.fdf";		// PROBLEME
	// data.file.name = "test_maps/elem2.fdf";
	// data.file.name = "test_maps/elem.fdf";
	// data.file.name = "test_maps/julia.fdf";			// PROBLEME
	// data.file.name = "test_maps/mars.fdf";			// PROBLEME
	// data.file.name = "test_maps/pentenegpos.fdf";
	// data.file.name = "test_maps/plat.fdf";
	// data.file.name = "test_maps/pnp_flat.fdf";
	// data.file.name = "test_maps/pylone.fdf";
	// data.file.name = "test_maps/pyra.fdf";
	// data.file.name = "test_maps/pyramide.fdf";
	// data.file.name = "test_maps/t1.fdf";
	// data.file.name = "test_maps/t2.fdf";