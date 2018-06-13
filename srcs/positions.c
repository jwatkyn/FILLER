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

int		ft_get_no_pos(t_map *map, t_piece *p)
{
	int	x;
	int	y;
	int	i;
	int	flag;
}

void	ft_get_positions(t_map *map, t_piece *p)
{
	int	x;
	int	y;
	int	i;
	int	flag;

	y = 0;
	i = 0;
	fprintf(stderr, "hello\n");
	fflush(stderr);
	count = ft_get_no_pos(map, p)
	while (y++ < map->mapsize_y)
	{
		x = 0;
		if (y + p->psize_y >= map->mapsize_y)
			break ;
		while (x++ < map->mapsize_x)
		{
			if (x + p->psize_x < map->mapsize_x)
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
	while(j++ < p->psize_y)
	{
		i = 0;
		while(i++ < p->psize_x)
		{
			if (p->piece[j][i] == '*')
				if (map->map[y + j][x + i] == (map->m_p || map->m_p - 32))
					flag_1++;
			if (p->piece[j][i] == '*')
				if (map->map[y + j][x + i] == (map->e_p || map->e_p - 32))
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
