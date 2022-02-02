/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:39:30 by ski               #+#    #+#             */
/*   Updated: 2022/02/01 16:39:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void init_table(t_p *table, int size_l, int size_c)
{
	int l;
	int c;
	int z = 0;

	l = 0;
	c = 0;
	table[l * size_l + c] = (t_p){0, 0, z};
	l = 0;
	c = 1;
	table[l * size_l + c] = (t_p){0, 1, z};
	l = 0;
	c = 2;
	table[l * size_l + c] = (t_p){0, 2, z};

	l = 1;
	c = 0;
	table[l * size_l + c] = (t_p){1, 0, z};
	l = 1;
	c = 1;
	table[l * size_l + c] = (t_p){1, 1, 1};
	l = 1;
	c = 2;
	table[l * size_l + c] = (t_p){1, 2, z};

	l = 2;
	c = 0;
	table[l * size_l + c] = (t_p){2, 0, z};
	l = 2;
	c = 1;
	table[l * size_l + c] = (t_p){2, 1, z};
	l = 2;
	c = 2;
	table[l * size_l + c] = (t_p){2, 2, z};

	c = size_c;

	return ;
}


