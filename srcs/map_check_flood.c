/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <mabenois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:18:19 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/26 16:01:18 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_check.h"

void	ft_copy_map_to_int(unsigned int *tab, t_map *map)
{
	t_map_node		*curr;
	unsigned int	i;
	unsigned int	j;

	curr = map->head;
	j = 0;
	while (curr->next != NULL)
	{
		i = 0;
		while (i < map->w - 1)
		{
			if (curr->line[i] == '1')
				tab[j] = 1;
			else if (curr->line[i] == 'P')
				tab[j] = 2;
			else
				tab[j] = 0;
			i++;
			j++;
		}
		curr = curr->next;
	}
}
