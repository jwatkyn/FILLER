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

	y = -1;
	i = 0;
	while (++y + p->psize_y <= map->mapsize_y)
	{
		x = -1;
		while (++x + p->psize_x <= map->mapsize_x)
		{
			flag = ft_piece_map(map, p, x, y);
			if (flag == 1)	
				i++;
		}
	}
	return (i);
}

void	ft_get_positions(t_map *map, t_piece *p)
{
	int	x;
	int	y;
	int	i;
	int	flag;
	int	count;

	y = -1;
	i = 0;
	count = ft_get_no_pos(map, p);
	if (count == 0)
		return ;
	p->possible_pos = (int**)malloc(sizeof(int*) * count);
	while (++y + p->psize_y <= map->mapsize_y)
	{
		x = -1;
		while (++x + p->psize_x <= map->mapsize_x)
		{
			flag = ft_piece_map(map, p, x, y);
			if (flag == 1)
			{
				p->possible_pos[i] = (int*)malloc(sizeof(int) * 3);
				p->possible_pos[i][0] = x;
				p->possible_pos[i][1] = y;
				p->possible_pos[i++][2] = 0;
			}
		}
	}
	p->pp_size = count;
}

int		ft_piece_map(t_map *map, t_piece *p, int x, int y)
{
	int	i;
	int	j;
	int	flag_1;
	int	flag_2;

	j = -1;
	flag_1 = 0;
	flag_2 = 0;
	while(++j < p->psize_y)
	{
		i = -1;
		while(++i < p->psize_x)
		{
			if (p->piece[j][i] == '*')
			{

				if (map->map[y + j][x + i] == map->m_p || 
					map->map[y + j][x + i] == map->m_p + 32)
					flag_1 = flag_1 + 1;
				if (map->map[y + j][x + i] == map->e_p || 
					map->map[y + j][x + i] == map->e_p + 32)
					flag_2 = flag_2 + 1;
			}
			if (flag_1 > 1 || flag_2 > 0)
				break ;
		}
		if (flag_1 > 1 || flag_2 > 0)
			break ;
	}
	if (flag_1 == 1 && flag_2 == 0)
	{
		return (1);
	}
	else
		return (0);
}