/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:07:34 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/11 12:13:18 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft/includes/libft.h"

int	main(void)
{
	char	*line;
	int f = open("output.txt", 1);
	int i = 0;
	while (i++ < 3)
	{
		get_next_line(0, &line);
		if (ft_strcmp(line, "$$$ exec p1 : [players/dpoulter.filler]\n"))
			ft_putendl_fd("p1", f);
		else
			ft_putendl_fd(line, f);
		free(line);
	}
	close(f);
	return (0);
}
