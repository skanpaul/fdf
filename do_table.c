/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:42:45 by ski               #+#    #+#             */
/*   Updated: 2022/02/04 11:42:47 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static void	take_point_from_file(t_p *xyz, t_it *info_table, t_file *file);
static int	check_column(char *line, char **split, t_it *info_table, int *y);

/* ************************************************************************** */
t_p	*do_table(t_file *file, t_it *info_table)
{
	t_p		*xyz;

	file->fd = open(file->name, O_RDONLY);
	if (file->fd == -1)
		return (NULL);
	xyz = (t_p *)malloc((info_table->max_l * info_table->max_c) * sizeof(t_p));
	take_point_from_file(xyz, info_table, file);
	close(file->fd);
	return (xyz);
}

/* ************************************************************************** */
static void	take_point_from_file(t_p *xyz, t_it *info_table, t_file *file)
{
	int		x;
	int		y;
	char	*line;
	char	**split;

	y = 0;
	while (y < info_table->max_l)
	{
		line = get_next_line(file->fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		if (check_column(line, split, info_table, &y) == ERROR_COLUMN_AMOUNT)
			break ;
		x = 0;
		while (x < info_table->max_c)
		{
			xyz[x + y * info_table->max_c]
				= (t_p){.x = x, .y = y, .z = ft_atoi(split[x])};
			x++;
		}
		ft_split_free(split);
		free(line);
		y++;
	}
}

/* ************************************************************************** */
static int	check_column(char *line, char **split, t_it *info_table, int *y)
{
	int	error;

	error = NO_ERROR;
	if (ft_split_count(split) != info_table->max_c)
	{
		ft_printf("Ligne [%d] n'a pas le bon nombre de colonne\n", *y);
		ft_printf("Nombe de colonne REELLE %d\n", ft_split_count(split));
		ft_printf("Nombe de colonne ATTENDU %d\n", info_table->max_c);
		info_table->max_l = *y - 1;
		ft_printf("On affichera jusqu a la ligne [%d]\n", info_table->max_l);
		ft_split_free(split);
		free(line);
		error = ERROR_COLUMN_AMOUNT;
	}
	return (error);
}
