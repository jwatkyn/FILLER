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
	if (map->mapsize[0] == 0 && map->mapsize[1] == 0)
		ft_mapsize(map, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	y = 0;
	map->map = (char**)malloc(sizeof(char*) * map->mapsize[0]);
	while(y++ < map->mapsize[0])
	{
		get_next_line(0, &line);
		map->map[y] = ft_strdup((char const *)&line[4]);
		ft_strdel(&line);
	}
	ft_get_enemypos(map);
	ft_get_mypos(map);
}

void	ft_mapsize(t_map *map, char *line)
{
	char	*num1;
	char	*num2;
	
	num1 = ft_strstr(line, "(");
	num2 = ft_strstr(num1, " ");
	map->mapsize[0] = ft_atoi(num1); 
	map->mapsize[1] = ft_atoi(num2);
}

void	ft_initialise_info(t_map *map)
{
	// char	*line;

	// get_next_line(0, &line);
	// printf("%s", line);
	// if (strncmp(line, "$$$", 2) == 0 && map->player == 0)
	// {
	// 	if (ft_strstr(line, "p2"))
	// 	{
	// 		map->m_p = 'x';
	// 		map->e_p = 'o';
	// 		map->player = 2;
	// 	}
	// 	if (ft_strstr(line, "p1"))
	// 	{
	// 		map->m_p = 'o';
	// 		map->e_p = 'x';
	// 		map->player = 1;
	// 	}
	// }
	map->m_p = 'o';
// 	int f = open("output.txt", 1);
// 	while (get_next_line(0, &line) == 1)
// 	{
// 		if (ft_strcmp(line, "$$$ exec p1 : [players/jwatkyn.filler]\n"))
// 			ft_putendl_fd("p1", f);
// 		else
// 			ft_putendl_fd(line, f);
// 		free(line);
// 	}
// 	free(line);
}

void	ft_get_psize(t_piece *p, char *line)
{
	char	*num1;
	char	*num2;

	num1 = ft_strstr(line, " ");
	num2 = ft_strstr(num1, " ");
	p->psize[0] = ft_atoi(num1);
	p->psize[1] = ft_atoi(num2);
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
	while (y++ < p->psize[1])
	{
		get_next_line(0, &line);
		x = 0;
		while (x++ < p->psize[0])
		{
			if (line[x] == '*')
			{
				p->real_piece[p->fp_size][0] = x;
				p->real_piece[p->fp_size++][1] = y;
			}
			else
			{
				p->false_piece[p->fp_size][0] = x;
				p->false_piece[p->fp_size++][1] = y;
			}
		}
		ft_strdel(&line);
	}
}
