/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:16:27 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/11 11:16:29 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_struct(t_map *map, t_piece *p)
{
	map->map = NULL;
	map->player = 0;
//	map->mapsize = {0,0};
	map->e_p = 0;
	map->m_p = 0;
	map->ep_size = 0;
	map->mp_size = 0;
	map->e_shape = 0;
	map->e_density = 0;
	map->touch = 0;
	p->piece = NULL;
//	p->psize = {0,0};
	p->real_piece = NULL;
	p->rp_size = 0;
	p->false_piece = NULL;
	p->fp_size = 0;
	p->possible_pos = NULL;
	p->pp_size = 0;
//	p->fin_pos = {0,0};
//	p->cur_pos = {0,0};
}

int	main(void)
{
	// t_map	*map;
	// t_piece	*p;
	char *line;

	int f = open("output.txt", 1);
	while (get_next_line(0, &line) == 1)
	{
		if (!(ft_strcmp(line, "$$$ exec p1 : [./players/jwatkyn.filler]\n")))
			ft_putendl_fd("p1", f);
		else
			ft_putendl_fd(line, f);
		free(line);
	}

// 	map = (t_map *)malloc(sizeof(*map));
// 	p = (t_piece *)malloc(sizeof(*p));
// 	ft_init_struct(map, p);
// 	ft_initialise_info(map);
// 	while (map->ret != -1)
// 	{
// 		ft_get_map(map);
// 		ft_get_piece(p);
// 		ft_get_positions(map, p);
// 		write(0, "0 0\n", 4);
// 		break ;
// //		ft_get_enemy_info(map);
// //		ft_get_strategy(map, p);
// //		ft_get_position_val(map, p);
// //		ft_print_final(map, p);
// 	}
// 	free(map);
// 	free(p);
// 	return (0);
}