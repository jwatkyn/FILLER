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

void	ft_get_enemypos(t_map *mapping)
{
	char	**map;
	int		x;
	int		y;
	int		size;

	map = mapping->map;
	y = 0;
	size = 0;
	while (y++ < mapping->mapsize[1])
	{
		x = 0;
		while (x++ < mapping->mapsize[0])
			if (map[y][x] == mapping->e_p)
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

	map = mapping->map;
	y = 0;
	size = 0;
	while (y++ < mapping->mapsize[1])
	{
		x = 0;
		while (x++ < mapping->mapsize[0])
			if (map[y][x] == mapping->m_p)
			{
				mapping->my_pos[size][0] = y;
				mapping->my_pos[size++][1] = x;
			}
	}
	mapping->mp_size = size;
}
