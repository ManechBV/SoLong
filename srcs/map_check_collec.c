/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_collec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:14:08 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/09 18:31:17 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_check.h"

int	ft_check_collec(t_map *map)
{
	t_check		*check;
	t_map_node	*curr;
	int			j;
	int			i;

	check = ft_new_check(map);
	if (ft_check_map(map, check) != 0 || ft_check_map_border(map) != 0)
		return (ft_free_check(check, -1));
	ft_flood_fill(map, check->flood_map);
	i = 0;
	curr = map->head;
	while (curr->next)
	{
		j = -1;
		while (curr->line[++j])
		{
			if (curr->line[j] == 'C' && check->flood_map[i] != 2)
				return (ft_free_check(check, -1));
			if (curr->line[j] != '\n')
				i++;
		}
		curr = curr->next;
	}
	ft_free_check(check, 0);
	return (0);
}
