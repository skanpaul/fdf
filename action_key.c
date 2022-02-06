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
static void free_malloc(t_p *table_1);
static void action_key_rotation(int key, t_data *data);
static void action_key_decalage(int key, t_data *data);
static void action_key_perspective(int key, t_data *data);
/* ************************************************************************** */
int action_key(int key, void *param)
{
	t_data *data;
	data = (t_data *)param;

	ft_printf("Touche: %d\n", key);
	action_key_rotation(key, data);
	action_key_decalage(key, data);
	action_key_perspective(key, data);
	/* ----------------------------------------------------- */
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		free_malloc(data->xyz);
		exit(0);
	}
	return (0);
}

/* ************************************************************************** */
static void free_malloc(t_p *table_1)
{
	if (table_1)
		free(table_1);
}

/* ************************************************************************** */
void action_key_rotation(int key, t_data *data)
{
	int inc;
	
	inc = 5;
	/* ---------------------------------------------- Z-axis */
	if (key == KEY_X)
	{
		data->alpha_z += inc * (2 * M_PI / 360);
		rendering(data->xyz, data);
	}
	if (key == KEY_Z)
	{
		data->alpha_z -= inc * (2 * M_PI / 360);
		rendering(data->xyz, data);	
	}
	/* ---------------------------------------------- X-axis */
	if (key == KEY_C)
	{
		data->alpha_x += inc * (2 * M_PI / 360);
		rendering(data->xyz, data);
	}
	if (key == KEY_V)
	{
		data->alpha_x -= inc * (2 * M_PI / 360);
		rendering(data->xyz, data);	
	}
	/* ---------------------------------------------- Y-axis */
	if (key == KEY_B)
	{
		data->alpha_y += inc * (2 * M_PI / 360);
		rendering(data->xyz, data);
	}
	if (key == KEY_N)
	{
		data->alpha_y -= inc * (2 * M_PI / 360);
		rendering(data->xyz, data);	
	}
}
/* ************************************************************************** */
static void action_key_decalage(int key, t_data *data)
{
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
}

/* ************************************************************************** */
static void action_key_perspective(int key, t_data *data)
{
	/* ----------------------------------------------------- */
	if (key == KEY_K)
	{
		init_vector_unit_standard(data);
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_L)
	{
		init_vector_unit_iso(data);
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
}

/* ************************************************************************** */


	/* ----------------------------------------------------- */
	// if (key == KEY_D)
	// {
	// 	rendering(data->xyz, data);
	// }
	/* ----------------------------------------------------- */
	/* ----------------------------------------------------- */
	// if (key == KEY_G)
	// {
	// 	printf("G appuyé\n");
	// 	draw_grid(100, data, COLOR_BLUE);
	// }
	// /* ----------------------------------------------------- */
	// if (key == KEY_C)
	// {
	// 	printf("C appuyé\n");
	// 	draw_clean(data);
	// 	free_malloc(data->xyz);
	// 	// free_malloc(xyz, zoom, deform, decal);
	// }