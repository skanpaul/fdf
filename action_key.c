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
void free_malloc(t_p *table_1, t_p *table_2, t_p *table_3, t_p *table_4);

/* ************************************************************************** */
int action_key(int key, void *param)
{
	/* vecteur UNITAIRE ------------------------------------ */
	t_p v_i = {.x = 2, 		.y = 1, 	.z = 0};
	t_p v_j = {.x = -2, 	.y = 1, 	.z = 0};
	t_p v_k = {.x = 0, 		.y = -1, 	.z = 0};
	/* vecteur DECALAGE ------------------------------------ */
	int x_decal = W_WIDTH / 2;
	int y_decal = 100;
	t_p v_decal = {	.x = x_decal, 	.y = y_decal};
	/* vecteur ZOOM ---------------------------------------- */
	int x_fact = 20;
	int y_fact = 20;
	int z_fact = 10;
	t_p factor = {.x = x_fact, .y = y_fact, .z = z_fact};
	/* TABLE ----------------------------------------------- */
	t_p *xyz = NULL;
	t_p *zoom = NULL;
	t_p *deform = NULL;
	t_p *decal = NULL;
	/* ----------------------------------------------------- */
	t_data *data;
	data = (t_data *)param;
	/* ----------------------------------------------------- */
	int max_l;
	int max_c;
	/* ----------------------------------------------------- */
	t_file	file;
	t_it	info_table;
	file.name = "texte";


	/* ----------------------------------------------------- */
	if (key == KEY_D)
	{
		/* MANUEL ---------------------------------------------- */
		// max_l = 4; // LIGNE
		// max_c = 2; // COLONNE
		// xyz = (t_p *)malloc((max_l * max_c) * sizeof(t_p));
		// init_table(xyz, max_l, max_c);
		/* AUTOMATIQUE ----------------------------------------- */
		xyz = get_data_from_file(&file, &info_table);
		if (xyz == NULL)
			return (0);
		max_c = info_table.max_c;
		max_l = info_table.max_l;
		/* ----------------------------------------------------- */
		zoom = trans_zoom(xyz, max_l, max_c, factor);
		deform = trans_deform(zoom, max_l, max_c, v_i, v_j, v_k);
		decal = trans_decal(deform, max_l, max_c, v_decal);
		draw(decal, max_l, max_c, data);
		free_malloc(xyz, zoom, deform, decal);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_C)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_grid(100, data, COLOR_BLUE);		
		free_malloc(xyz, zoom, deform, decal);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);		
		free_malloc(xyz, zoom, deform, decal);
		exit(0);
	}
	/* ----------------------------------------------------- */
	return (0);
}

/* ************************************************************************** */

void free_malloc(t_p *table_1, t_p *table_2, t_p *table_3, t_p *table_4)
{
	if (table_1)
		free(table_1);
	if (table_2)
		free(table_2);
	if (table_3)
		free(table_3);
	if (table_4)
		free(table_4);
}