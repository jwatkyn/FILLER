#include "filler.h"

void	ft_get_map(t_map *map)
{
	char	*line;
	int 	y;

	get_next_line(0, &line);
	if (map->mapsize == {0,0})
		ft_mapsize(map, line)
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	y = 0;
	while(y++ < map->mapsize[1])
	{
		get_next_line(0, &line);
		map->map[y] = ft_strdup((char const *)(line[4]));
		ft_strdel(&line);
	}
	ft_get_enemypos(map);
	ft_get_mypos(map);
}

void	ft_mapsize(t_map map, line)
{
	char	*num1;
	char	*num2;
	
	num1 = ft_strstr(line, "(");
	num2 = ft_strstr(num1, " ");
	map->mapsize = {ft_atoi(num1), ft_atoi(num2)};
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
	free(line);
}

void	ft_get_piece(t_piece p)
{
	char	*line;
	int 	x;
	int 	y;

	get_next_line(0, &line);
	ft_get_psize(p, line);
	ft_strdel(&line);
	y = 0;
	while (y++ < p->size[1])
	{
		get_next_line(0, &line);
		x = 0;
		while (x++ < p->size[0])
		{
			if (line[x] == '*')
				p->real_piece[p->rp_size++] = {x, y};
			else
				p->false_piece[p->fp_size++] = {x, y};
		}
		ft_strdel(&line);
	}
}

void	ft_get_psize(t_piece p, char *line)
{
	char	*num1;
	char	*num2;

	num1 = ft_strstr(line, " ");
	num2 = ft_strstr(num1, " ");
	p->size[0] = ft_atoi(num1);
	p->size[1] = ft_atoi(num2);
}