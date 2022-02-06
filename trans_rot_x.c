/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_rot_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:17:18 by ski               #+#    #+#             */
/*   Updated: 2022/02/02 08:17:20 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
t_p *trans_rot_x (t_p *input, t_data *data, double alpha)
{
	double cos_alpha;
	double sin_alpha;
	int x;
	int y;
	int max_c;
	int max_l;
	t_p *output;

	max_c = data->info_table.max_c;
	max_l = data->info_table.max_l;

	cos_alpha = cos(alpha);
	sin_alpha = sin(alpha);

	output =(t_p *)malloc((max_l * max_c) * sizeof(t_p));

	y = 0;
	while (y < max_l)
	{
		x = 0;
		while (x < max_c)
		{
			output[x + y * max_c].x = input[x + y * max_c].x;
			output[x + y * max_c].y = 
					input[x + y * max_c].y * cos_alpha
				+ 	input[x + y * max_c].z * (-sin_alpha);

			output[x + y * max_c].z = 
					input[x + y * max_c].y * sin_alpha
				+ 	input[x + y * max_c].z * cos_alpha;
			x++;
		}	
		y++;
	}

	return (output);
}