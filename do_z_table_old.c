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
// #include "main.h"

// /* ************************************************************************** */
// static int	*add_z_to_table(int z, int *old_z_table, int pos_z);
// static int	copy_z_table(int *new_z_table, int *old_z_table, int pos_z);

// /* ************************************************************************** */
// int	*do_z_table(t_file *file, t_it *info_table)
// {
// 	char	*line;
// 	char	**split;
// 	int		*z_table;
// 	int		pos_z;
// 	int		i;

// 	z_table = NULL;
// 	pos_z = 0;
// 	while (1)
// 	{
// 		line = get_next_line(file->fd);
// 		if (!line)
// 			break ;
// 		info_table->max_l += 1;
// 		split = ft_split(line, ' ');
// 		info_table->max_c = ft_split_count(split);
// 		i = 0;
// 		while (i < info_table->max_c)
// 		{
// 			z_table = add_z_to_table(ft_atoi(split[i]), z_table, pos_z);
// 			i++;
// 			pos_z++;
// 		}
// 	}
// 	return (z_table);
// }

// /* ************************************************************************** */
// static int	*add_z_to_table(int z, int *old_z_table, int pos_z)
// {
// 	int	*new_z_table;
// 	int	i;

// 	new_z_table = NULL;
// 	if (pos_z == 0)
// 	{
// 		new_z_table = (int *)malloc(1 * sizeof(int));
// 		if (!new_z_table)
// 			return (NULL);
// 		new_z_table[pos_z] = z;
// 	}
// 	else
// 	{
// 		new_z_table = (int *)malloc((pos_z + 1) * sizeof(int));
// 		if (!new_z_table)
// 			return (NULL);
// 		i = copy_z_table(new_z_table, old_z_table, pos_z);
// 		new_z_table[i] = z;
// 		free (old_z_table);
// 	}
// 	return (new_z_table);
// }

// /* ************************************************************************** */
// static int	copy_z_table(int *new_z_table, int *old_z_table, int pos_z)
// {
// 	int	i;

// 	i = 0;
// 	while (i < pos_z)
// 	{
// 		new_z_table[i] = old_z_table[i];
// 		i++;
// 	}
// 	return (i);
// }
