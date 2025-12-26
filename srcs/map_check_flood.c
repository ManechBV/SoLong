/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <mabenois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:18:19 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/26 16:55:46 by mabenois         ###   ########.fr       */
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

int	ft_check_map_and_flood(t_map *map)
{
	t_check	*check;

	check = ft_new_check(map);
	if (ft_check_map(map, check) != 0)
	{
		ft_free_check(check);
		return (-1);
	}

	unsigned int	i = 0;
	ft_printf("\ncheck_flood:\n");
	while (i < (map->w - 1) * map->h)
	{
		if (i % (map->w - 1) == 0)
			ft_printf("\n");
		ft_printf("%d", check->flood_map[i]);
		i++;
	}

	ft_free_check(check);
	return (0);
}
