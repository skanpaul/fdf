/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:13:16 by ski               #+#    #+#             */
/*   Updated: 2022/02/02 15:13:18 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int ft_split_count(char **split_table)
{
	int i;

	if(!split_table)
		return (0);
	i = 0;
	while(split_table[i] != NULL)
		i++;
	return (i);
}

