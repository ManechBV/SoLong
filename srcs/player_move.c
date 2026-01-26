/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:58:44 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/26 20:22:05 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_strichr.h"

void	ft_player_move(t_vars *vars, int dir)
{
	t_map_node	*curr;
	int			player_pos;
	char		*dest;

	curr = vars->map->head;
	while (curr->next != NULL)
	{
		player_pos = ft_strichr(curr->line, 'P');
		if (player_pos != -1)
		{
			if (dir == 0)
				dest = &curr->line[player_pos + 1];
			if (dir == 1)
				dest = &curr->line[player_pos - 1];
			if (dir == 2)
				dest = &curr->next->line[player_pos];
			if (dir == 3)
				dest = &curr->prev->line[player_pos];
			if (*dest != '1')
				ft_player_try_move(vars, &curr->line[player_pos], dest);
			break ;
		}
		curr = curr->next;
	}
}

void	ft_player_try_move(t_vars *vars, char *from, char *dest)
{
	char		tmp;

	tmp = *dest;
	*dest = 'P';
	*from = vars->player->cell_below;
	vars->player->cell_below = tmp;
	vars->moves += 1;
}
