/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_zoom.x                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:48:57 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 17:49:02 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
t_p *trans_zoom(t_p *input, int max_l, int max_c, t_p factor)
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
			output[x + y * max_c].x = input[x + y * max_c].x * factor.x;
			output[x + y * max_c].y = input[x + y * max_c].y * factor.y;
			output[x + y * max_c].z = input[x + y * max_c].z * factor.z;
			x++;
		}	
		y++;
	}
	

	return (output);
}

