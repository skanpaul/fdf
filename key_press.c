/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
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
int key_press(int key, void *param)
{
	/* ----------------------------------------------------- */
	t_data *data;
	data = (t_data *)param;
	/* ----------------------------------------------------- */

	int size_l = 3;
	int size_c = 3;

	t_p *table_1;
	t_p *table_2;
	t_p *table_3;
	t_p *table_4;

	t_p v_decal = {	.x = W_WIDTH / 2, 	.y = 100 };
	t_p factor = {	.x = 25, 			.y = 25, 	.z = 100};

	t_p v_i = {	.x = 2, 				.y = 1, 	.z = 0};
	t_p v_j = {.x = -2, 				.y = 1, 	.z = 0};
	t_p v_k = {.x = 0, 					.y = -1, 	.z = 0};
	
	/* ----------------------------------------------------- */
	table_1 = NULL;
	table_2 = NULL;
	table_3 = NULL;
	table_4 = NULL;

	/* ----------------------------------------------------- */
	if (key == KEY_D)
	{
		table_1 = (t_p *)malloc((size_l * size_c) * sizeof(t_p));

		//IMPORTANT
		init_table(table_1, size_l, size_c);

		table_2 = trans_zoom(table_1, size_l, size_c, factor);

		table_3 = trans_deform(table_2, size_l, size_c, v_i, v_j, v_k);
		table_4 = trans_decal(table_3, size_l, size_c, v_decal);

		draw(table_4, size_l, size_c, data);

		free_malloc(table_1, table_2, table_3, table_4);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_C)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_grid(100, data, COLOR_BLUE);

		free_malloc(table_1, table_2, table_3, table_4);
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);

		free_malloc(table_1, table_2, table_3, table_4);

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