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
static void	fct_1(t_p p_xy, t_p *output, t_p *input, t_data *data);

/* ************************************************************************** */
t_p	*trans_deform(t_p *input, t_data *data)
{
	int	y;
	int	x;
	t_p	p_xy;
	t_p	*output;

	output = (t_p *)malloc((data->info_table.max_l * data->info_table.max_c)
			* sizeof(t_p));
	y = 0;
	while (y < data->info_table.max_l)
	{
		x = 0;
		while (x < data->info_table.max_c)
		{
			p_xy = (t_p){.x = x, .y = y};
			fct_1(p_xy, output, input, data);
			x++;
		}	
		y++;
	}
	return (output);
}

/* ************************************************************************** */
static void	fct_1(t_p p_xy, t_p *output, t_p *input, t_data *data)
{
	int	max_c;
	int	max_l;
	int	y;
	int	x;

	x = p_xy.x;
	y = p_xy.y;
	max_c = data->info_table.max_c;
	max_l = data->info_table.max_l;
	output[x + y * max_c].x
		= input[x + y * max_c].x * data->vu_i.x
		+ input[x + y * max_c].y * data->vu_j.x
		+ input[x + y * max_c].z * data->vu_k.x;
	output[x + y * max_c].y
		= input[x + y * max_c].x * data->vu_i.y
		+ input[x + y * max_c].y * data->vu_j.y
		+ input[x + y * max_c].z * data->vu_k.y;
}
