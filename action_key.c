/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:01:26 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 14:01:28 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
// void free_malloc(t_p *table_1, t_p *table_2, t_p *table_3, t_p *table_4);
static void free_malloc(t_p *table_1);
/* ************************************************************************** */
int action_key(int key, void *param)
{
	t_data *data;

	/* TABLE ----------------------------------------------- */
	// t_p *xyz = NULL;
	// t_p *zoom = NULL;
	// t_p *deform = NULL;
	// t_p *decal = NULL;
	/* ----------------------------------------------------- */
	data = (t_data *)param;

	ft_printf("Touche: %d\n", key);
	/* ----------------------------------------------------- */
	if (key == KEY_D)
	{
		// xyz = get_data_from_file(&(data->file), &(data->info_table));
		// if (xyz == NULL)
		// 	return (0);
		rendering(data->xyz, data);
		/* ----------------------------------------------------- */
		// zoom = trans_zoom(xyz, data);
		// deform = trans_deform(zoom, data);
		// decal = trans_decal(deform, data);
		// draw(decal, data);
		// free_malloc(xyz, zoom, deform, decal);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ARROW_UP)
	{
		data->decal.y -= 20;
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ARROW_DOWN)
	{
		data->decal.y += 20;
		rendering(data->xyz, data);		
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ARROW_LEFT)
	{
		data->decal.x -= 20;
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ARROW_RIGHT)
	{
		data->decal.x += 20;
		rendering(data->xyz, data);		
	}
	/* ----------------------------------------------------- */
	if (key == KEY_V)
	{
		printf("V appuyé\n");
		init_vector_unit_standard(data);
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_W)
	{
		printf("V appuyé\n");
		init_vector_unit_iso(data);
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_G)
	{
		printf("G appuyé\n");
		draw_grid(100, data, COLOR_BLUE);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_C)
	{
		printf("C appuyé\n");
		draw_clean(data);
		free_malloc(data->xyz);
		// free_malloc(xyz, zoom, deform, decal);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		free_malloc(data->xyz);
		// free_malloc(xyz, zoom, deform, decal);
		exit(0);
	}
	/* ----------------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
static void free_malloc(t_p *table_1)
{
	if (table_1)
		free(table_1);
}

/* ************************************************************************** */
	// file.name = "test_maps/texte";
	// file.name = "test_maps/10-2.fdf";
	// file.name = "test_maps/10-70.fdf";		// depasse en haut
	// file.name = "test_maps/100-6.fdf"; 		// depasse peut etre gauche et droite
	// file.name = "test_maps/20-60.fdf";		// depasse en haut
	// file.name = "test_maps/42.fdf";
	// file.name = "test_maps/50-4.fdf";
	// file.name = "test_maps/basictest.fdf";
	// file.name = "test_maps/elem-col.fdf";
	// file.name = "test_maps/elem-fract.fdf";	// PROBLEME
	// file.name = "test_maps/elem2.fdf";
	// file.name = "test_maps/elem.fdf";
	// file.name = "test_maps/julia.fdf";	// PROBLEME
	// file.name = "test_maps/mars.fdf";
	// file.name = "test_maps/pentenegpos.fdf";
	// file.name = "test_maps/plat.fdf";
	// file.name = "test_maps/pnp_flat.fdf";
	// file.name = "test_maps/pylone.fdf";
	// file.name = "test_maps/pyra.fdf";
	// file.name = "test_maps/pyramide.fdf";
	// file.name = "test_maps/t1.fdf";
	// file.name = "test_maps/t2.fdf";

/* ************************************************************************** */
	/* MANUEL ---------------------------------------------- */
	// max_l = 4; // LIGNE
	// max_c = 2; // COLONNE
	// xyz = (t_p *)malloc((max_l * max_c) * sizeof(t_p));
	// init_table(xyz, max_l, max_c);
	/* AUTOMATIQUE ----------------------------------------- */

/* ************************************************************************** */
	// /* ----------------------------------------------------- */

	// /* ----------------------------------------------------- */
	// t_file	file;
	// t_it	info_table;