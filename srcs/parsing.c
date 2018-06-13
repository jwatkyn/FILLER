/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:16:36 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/11 11:16:39 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_map(t_map *map)
{
	char	*line;
	int 	y;

	get_next_line(0, &line);
	if (map->mapsize_y == 0 && map->mapsize_x == 0)
		ft_mapsize(map, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	y = 0;
	map->map = (char**)malloc(sizeof(char*) * map->mapsize_y);
	while (y++ < map->mapsize_y)
	{
		get_next_line(0, &line);
		map->map[y] = (char*)malloc(sizeof(char) * map->mapsize_x);
		map->map[y] = ft_strdup((char const *)&line[4]);
		ft_strdel(&line);
	}
	ft_get_enemypos(map);
	ft_get_mypos(map);
}

void	ft_mapsize(t_map *map, char *line)
{
	int			i;
	int			temp;

	i = 0;
	map->mapsize_y = 0;
	map->mapsize_x = 0;
	while (line[i])
	{
		temp = 0;
		while (ft_isdigit(line[i]) == 1 && line[i])
		{
			temp += line[i] - 48;
			if (ft_isdigit(line[i + 1]) == 1)
				temp *= 10;
			i++;
		}
		if (map->mapsize_y == 0)
			map->mapsize_y = temp;
		else if (map->mapsize_x == 0)
			map->mapsize_x = temp;
		i++;
	}
}

void	ft_initialise_info(t_map *map)
{
	char	*line;

	get_next_line(0, &line);
	if (strncmp(line, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			map->m_p = 'x';
			map->e_p = 'o';
			map->player = 2;
		}
		if (ft_strstr(line, "p1"))
		{
			map->m_p = 'o';
			map->e_p = 'x';
			map->player = 1;
		}
	}
}

void	ft_get_psize(t_piece *p, char *line)
{
	char	*num1;
	char	*num2;

	num1 = ft_strstr(line, " ");
	num2 = ft_strstr(num1, " ");
	p->psize_y = ft_atoi(num1);
	p->psize_x = ft_atoi(num2);
}

void	ft_get_piece(t_piece *p)
{
	char	*line;
	int 	x;
	int 	y;

	get_next_line(0, &line);
	ft_get_psize(p, line);
	ft_strdel(&line);
	y = 0;
	p->piece = (char**)malloc(sizeof(char*) * p->psize_y);
	while (y++ < p->psize_y)
	{
		get_next_line(0, &line);
		x = 0;
		p->piece[y] = (char*)malloc(sizeof(char) * p->psize_x);
		p->piece[y] = line;
		ft_strdel(&line);
	}
}
