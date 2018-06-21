/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:16:58 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/11 11:17:01 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_final(t_piece *p)
{
	ft_putnbr_fd(p->possible_pos[0][1], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(p->possible_pos[0][0], 1);
	ft_putchar_fd('\n', 1);
}
