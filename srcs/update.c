/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:17:10 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/11 11:17:13 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_count(char **map, char c, int size_y, int size_x)
{
	int		count;
	char	cap;
	int		y;
	int		x;

	count  = 0;
	cap = c - 32;
	y = 0;
	while (y++ < size_y)
	{
		x = 0;
		while (x++ < size_x)
		{
			if (map[y][x] == c || map[y][x] == cap)
				count++;
		}
	}
	return (count);
}

void	ft_get_enemypos(t_map *mapping)
{
	char	**map;
	int		x;
	int		y;
	int		size;
	int		count;
	int		size_y;
	int		size_x;

	map = mapping->map;
	y = 0;
	size = 0;
	size_y = mapping->mapsize_y;
	size_x = mapping->mapsize_x;
	count = ft_count(map, mapping->e_p, size_y, size_x);
	mapping->enemy_pos = (int**)malloc(sizeof(int*) * count);
	while (y++ < size_y)
	{
		x = 0;
		while (x++ < size_x)
			if (map[y][x] == (mapping->e_p || mapping->e_p - 32))
			{
				mapping->enemy_pos[size][0] = y;
				mapping->enemy_pos[size++][1] = x;
				size++;
			}
	}
	mapping->ep_size = size;
}

void	ft_get_mypos(t_map *mapping)
{
	char	**map;
	int		x;
	int		y;
	int		size;
	int		size_y;
	int		size_x;
	int		count;

	map = mapping->map;
	y = 0;
	size = 0;
	size_y = mapping->mapsize_y;
	size_x = mapping->mapsize_x;
	count = ft_count(map, mapping->m_p, size_y, size_x);
	mapping->my_pos = (int**)malloc(sizeof(int*) * count);
	while (y++ < size_y)
	{
		x = 0;
		while (x++ < size_x)
			if (map[y][x] == (mapping->m_p || mapping->m_p - 32))
			{
				mapping->my_pos[size][0] = y;
				mapping->my_pos[size++][1] = x;
			}
	}
	mapping->mp_size = size;
}