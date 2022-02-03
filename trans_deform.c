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
t_p *trans_deform(t_p *input, int max_l, int max_c, t_p i, t_p j, t_p k)
{
	int y;
	int x;
	t_p *output;

	output =(t_p *)malloc((max_l * max_c) * sizeof(t_p));

	y = 0;
	while (y < max_l)
	{
		x = 0;
		while (x < max_c)
		{
			output[x + y * max_c].x = 
					input[x + y * max_c].x * i.x
				+ 	input[x + y * max_c].y * j.x
				+ 	input[x + y * max_c].z * k.x;
			output[x + y * max_c].y = 
					input[x + y * max_c].x * i.y
				+ 	input[x + y * max_c].y * j.y
				+ 	input[x + y * max_c].z * k.y;
			x++;
		}	
		y++;
	}

	return (output);
}
