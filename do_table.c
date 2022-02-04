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
t_p	*do_table(t_file *file, t_it *info_table)
{
	t_p		*t;
	int 	x;
	int 	y;
	char 	*line;
	char	**split;

	/* ------------------------------------------------------------------- */
	file->fd = open(file->name, O_RDONLY);
	if (file->fd == -1)
		return (NULL);
	/* ------------------------------------------------------------------- */
	t = (t_p *)malloc((info_table->max_l * info_table->max_c) * sizeof(t_p));	
	y = 0;
	while (y < info_table->max_l)
	{
		line = get_next_line(file->fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		if (ft_split_count(split) != info_table->max_c)
		{
			ft_printf("Ligne [%d] n'a pas le bon nombre de colonne\n", y);
			ft_printf("Nombe de colonne REELLE %d\n", ft_split_count(split));
			ft_printf("Nombe de colonne ATTENDU %d\n", info_table->max_c);
			info_table->max_l = y - 1;
			ft_printf("On affichera jusqu a la ligne [%d]\n", info_table->max_l);
			ft_split_free(split);	
			free(line);
			break ;
		}
		x = 0;
		while (x < info_table->max_c)
		{
			t[x + y * info_table->max_c]
					= (t_p){.x = x, .y = y, .z = ft_atoi(split[x])};
			x++;
		}
		ft_split_free(split);
		free(line);	
		y++;
	}

	/* ------------------------------------------------------------------- */
	close(file->fd);
	return (t);
}

