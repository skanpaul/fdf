/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_z_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:38:00 by ski               #+#    #+#             */
/*   Updated: 2022/02/02 16:38:01 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static int	*add_z_to_table(int z, int *old_z_table, int pos);

/* ************************************************************************** */
int	*do_z_table(t_file *file, t_it *info_table)
{
	char	*line;
	char	**split;
	int		*z_table;
	int		pos_z;
	int		z;
	int		i;

	z_table = NULL;
	pos_z = 0;
	while (1)
	{
		line = get_next_line(file->fd);
		if (!line)
			break ;
		info_table->max_l += 1;
		split = ft_split(line, ' ');
		info_table->max_c = ft_split_count(split);
		i = 0;
		while (i < info_table->max_c)
		{
			z = ft_atoi(split[i]);
			z_table = add_z_to_table(z, z_table, pos_z);
			i++;
			pos_z++;
		}
	}
	return (z_table);
}

/* ************************************************************************** */
static int *add_z_to_table(int z, int *old_z_table, int pos)
{
	int	*new_z_table;
	int	i;

	new_z_table = NULL;
	if (pos == 0)
	{
		new_z_table = (int *)malloc(1 * sizeof(int));
		if (!new_z_table)
			return (NULL);
		new_z_table[pos] = z;
	}
	else
	{
		new_z_table = (int *)malloc((pos + 1) * sizeof(int));
		if (!new_z_table)
			return (NULL);
		i = 0;
		while (i < pos)
		{
			new_z_table[i] = old_z_table[i];
			i++;
		}
		new_z_table[i] = z;
		free (old_z_table);
	}
	return (new_z_table);
}
