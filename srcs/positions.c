/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:16:47 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/11 11:16:48 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_positions(t_map *map, t_piece *p)
{
	int	x;
	int	y;
	int	i;
	int	flag;

	y = 0;
	i = 0;
	while (y++ < map->mapsize[1])
	{
		x = 0;
		if (y + p->psize[1] >= map->mapsize[1])
			break ;
		while (x++ < map->mapsize[0])
		{
			if (x + p->psize[0] < map->mapsize[0])
			{
				flag = ft_piece_map(map, p, x, y);
				if (flag == 1)
				{
					p->possible_pos[i][0] = x;
					p->possible_pos[i++][1] = y;
				}
			}
			else
				break ;
		}
	}
	p->pp_size = i;
}

int		ft_piece_map(t_map *map, t_piece *p, int x, int y)
{
	int	i;
	int	j;
	int	flag_1;
	int	flag_2;

	j = 0;
	flag_1 = 0;
	flag_2 = 0;
	while(j++ < p->psize[1])
	{
		i = 0;
		while(i++ < p->psize[0])
		{
			if (p->piece[j][i] == '*')
				if (map->map[y + j][x + i] == map->m_p)
					flag_1++;
			if (p->piece[j][i] == '*')
				if (map->map[y + j][x + i] == map->e_p)
					flag_2++;
			if (flag_1 > 1 || flag_2 > 0)
				break ;
		}
		if (flag_1 > 1 || flag_2 > 0)
			break ;
	}

	if (flag_1 == 1 && flag_2 == 0)
		return (1);
	else
		return (0);
}
