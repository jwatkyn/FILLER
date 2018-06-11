#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> 

typedef struct	s_map
{
	char	**map;
	int		player;
	int		*mapsize;
	char	e_p;
	char	m_p;
	int		**enemy_pos;
	int		ep_size;
	int		**my_pos;
	int		mp_size;
	int		e_shape;
	int		e_density;
	int 	strategy;	
	int		touch;
	int		ret;
}				t_map;

typedef	struct	s_piece
{
	char	**piece;
	int		*psize;
	int		**real_piece;
	int		rp_size;
	int		**false_piece;
	int		fp_size;
	int		**possible_pos;
	int		pp_size;
	int		*fin_pos;
	int		*cur_pos;
}				t_piece;

void			ft_init_struct(t_map *map, t_piece *p);
void			ft_initialise_info(t_map *map);
void			ft_get_mypos(t_map *mapping);
void			ft_get_enemypos(t_map *mapping);
void			ft_mapsize(t_map *map, char *line);
void			ft_get_map(t_map *map);
void			ft_get_piece(t_piece *p);
void			ft_get_positions(t_map *map, t_piece *p);
int				ft_piece_map(t_map *map, t_piece *p, int x, int y);

#endif
