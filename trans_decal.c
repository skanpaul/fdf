/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_decal.x                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:46:15 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 17:46:18 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
// static void check_pos_max(t_p *input, t_data *data);
// static void move_g_point_on_origin(t_p *input, t_data *data);

/* ************************************************************************** */
t_p *trans_decal(t_p *input, t_data *data)
{
	int y;
	int x;
	int max_c;
	int max_l;
	t_p *output;

	max_c = data->info_table.max_c;
	max_l = data->info_table.max_l;

	// check_pos_max(input, data);
	// move_g_point_on_origin(input, data);


	output =(t_p *)malloc((max_l * max_c) * sizeof(t_p));

	y = 0;
	while (y < max_l)
	{
		x = 0;
		while (x < max_c)
		{
			output[x + y * max_c].x = input[x + y * max_c].x + data->decal.x;
			output[x + y * max_c].y = input[x + y * max_c].y + data->decal.y;
			x++;
		}	
		y++;
	}

	return (output);
}

/* ************************************************************************** */
// static void check_pos_max(t_p *input, t_data *data)
// {
// 	int y;
// 	int x;
// 	int max_c;
// 	int max_l;

// 	max_c = data->info_table.max_c;
// 	max_l = data->info_table.max_l;

// 	y = 0;
// 	while (y < max_c)
// 	{
// 		x = 0;
// 		while (x < max_c)
// 		{
// 			if (input[x + y * max_c].x > data->max_up)
// 				data->max_up = input[x + y * max_c].x;
// 			if (input[x + y * max_c].x < data->max_down)
// 				data->max_down = input[x + y * max_c].x;
// 			if (input[x + y * max_c].y > data->max_right)
// 				data->max_right = input[x + y * max_c].y;
// 			if (input[x + y * max_c].y < data->max_left)
// 				data->max_left = input[x + y * max_c].y;
// 			x++;
// 		}	
// 		y++;
// 	}
// }

// /* ************************************************************************** */
// static void move_g_point_on_origin(t_p *input, t_data *data)
// {
// 	int y;
// 	int x;
// 	int move_x;
// 	int move_y;
// 	int max_c;
// 	int max_l;

// 	move_x = data->max_left + (data->max_right - data->max_left)/2;
// 	move_y = data->max_up + (data->max_down - data->max_up)/2;


// 	max_c = data->info_table.max_c;
// 	max_l = data->info_table.max_l;

// 	y = 0;
// 	while (y < max_c)
// 	{
// 		x = 0;
// 		while (x < max_c)
// 		{
// 			input[x + y * max_c].x -= move_x;
// 			input[x + y * max_c].y -= move_y;
// 			x++;
// 		}	
// 		y++;
// 	}
// }











/* ************************************************************************** */
// t_p *trans_decal(t_p *input, t_data *data)
// {
// 	int y;
// 	int x;
// 	int max_c;
// 	int max_l;

// 	max_c = data->info_table.max_c;
// 	max_l = data->info_table.max_l;

// 	t_p *output;

// 	output =(t_p *)malloc((max_l * max_c) * sizeof(t_p));

// 	y = 0;
// 	while (y < max_l)
// 	{
// 		x = 0;
// 		while (x < max_c)
// 		{
// 			output[x + y * max_c].x = input[x + y * max_c].x + data->decal.x;
// 			output[x + y * max_c].y = input[x + y * max_c].y + data->decal.y;
// 			x++;
// 		}	
// 		y++;
// 	}

// 	return (output);
// }
