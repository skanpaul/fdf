/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:34:59 by ski               #+#    #+#             */
/*   Updated: 2022/02/04 10:35:02 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void ft_split_free(char **split_table)
{
	int i;

	if(!split_table)
		return ;
	i = 0;
	while (split_table[i] != NULL)
	{
		free(split_table[i]);
		i++;
	}
	free(split_table);
}

