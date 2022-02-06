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
	if (key == KEY_X)
	{
		data->alpha_z += 2 * (2 * M_PI / 360);
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_Z)
	{
		data->alpha_z -= 2 * (2 * M_PI / 360);
		rendering(data->xyz, data);	
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
