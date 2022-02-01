/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_decal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:46:15 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 17:46:18 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
t_p *trans_decal(t_p *table, int size_l, int size_c, t_p v_decal)
{
	int l;
	int c;
	t_p *decal;

	decal =(t_p *)malloc((size_l * size_c) * sizeof(t_p));

	l = 0;
	while (l < size_l)
	{
		c = 0;
		while (c < size_c)
		{
			decal[l * size_l + c].x = table[l * size_l + c].x + v_decal.x;
			decal[l * size_l + c].y = table[l * size_l + c].y + v_decal.y;
			c++;
		}	
		l++;
	}

	return (decal);
}

/* ************************************************************************** */
	// line = 0; col = 0;
	// table_2[line][col] = (t_p){	.x = table[line][col].x + v_decal.x, 
	// 								.y = table[line][col].y + v_decal.y};
	// line = 0; col = 1;
	// table_2[line][col] = (t_p){	.x = table[line][col].x + v_decal.x, 
	// 								.y = table[line][col].y + v_decal.y};
	// line = 1; col = 0;
	// table_2[line][col] = (t_p){	.x = table[line][col].x + v_decal.x, 
	// 								.y = table[line][col].y + v_decal.y};
	// line = 1; col = 1;
	// table_2[line][col] = (t_p){	.x = table[line][col].x + v_decal.x, 
	// 								.y = table[line][col].y + v_decal.y};