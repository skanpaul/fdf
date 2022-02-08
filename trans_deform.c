/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_deform.x                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:46:23 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 17:46:25 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static void	transformation(t_data *data);

/* ************************************************************************** */
t_p	*trans_deform(t_p *input, t_data *data)
{
	int	y;
	int	x;
	int	max_c;
	int	max_l;

	max_c = data->info_table.max_c;
	max_l = data->info_table.max_l;
	data->output = (t_p *)malloc((max_l * max_c) * sizeof(t_p));
	data->input = input;
	y = 0;
	while (y < data->info_table.max_l)
	{
		x = 0;
		while (x < data->info_table.max_c)
		{
			data->x = x;
			data->y = y;
			transformation(data);
			x++;
		}	
		y++;
	}
	return (data->output);
}

/* ************************************************************************** */
static void	transformation(t_data *data)
{
	int	x;
	int	y;
	int	max_c;
	int	max_l;

	x = data->x;
	y = data->y;
	max_c = data->info_table.max_c;
	max_l = data->info_table.max_l;
	data->output[x + y * max_c].x
		= data->input[x + y * max_c].x * data->vu_i.x
		+ data->input[x + y * max_c].y * data->vu_j.x
		+ data->input[x + y * max_c].z * data->vu_k.x;
	data->output[x + y * max_c].y
		= data->input[x + y * max_c].x * data->vu_i.y
		+ data->input[x + y * max_c].y * data->vu_j.y
		+ data->input[x + y * max_c].z * data->vu_k.y;
}
