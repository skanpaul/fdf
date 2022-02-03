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
t_p *trans_decal(t_p *input, int max_l, int max_c, t_p v_decal)
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
			output[x + y * max_c].x = input[x + y * max_c].x + v_decal.x;
			output[x + y * max_c].y = input[x + y * max_c].y + v_decal.y;
			x++;
		}	
		y++;
	}

	return (output);
}

/* ************************************************************************** */
	// line = 0; col = 0;
	// table_2[line][col] = (t_p){	.x = input[line][col].x + v_decal.x, 
	// 								.y = input[line][col].y + v_decal.y};
	// line = 0; col = 1;
	// table_2[line][col] = (t_p){	.x = input[line][col].x + v_decal.x, 
	// 								.y = input[line][col].y + v_decal.y};
	// line = 1; col = 0;
	// table_2[line][col] = (t_p){	.x = input[line][col].x + v_decal.x, 
	// 								.y = input[line][col].y + v_decal.y};
	// line = 1; col = 1;
	// table_2[line][col] = (t_p){	.x = input[line][col].x + v_decal.x, 
	// 								.y = input[line][col].y + v_decal.y};