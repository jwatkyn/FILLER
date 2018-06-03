#include "filler.h"

void	ft_get_enemypos(t_map mapping)
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
			if (map[y][x] = mapping->e_p)
			{
				mapping->enemy_pos[size] = [y][x];
				size++;
			}
	}
	mapping->ep_size = size;
}

void	ft_get_mypos(t_map mapping)
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
			if (map[y][x] = mapping->m_p)
			{
				map->my_pos[size] = [y][x];
				size++;
			}
	}
	mapping->mp_size = size;
}