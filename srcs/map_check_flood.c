/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <mabenois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:18:19 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/26 20:33:10 by mabenois         ###   ########.fr       */
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
			else if (curr->line[i] == 'E')
				tab[j] = 3;
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
	t_check			*check;
	unsigned int	i;

	check = ft_new_check(map);
	if (ft_check_map(map, check) != 0 || ft_check_map_border(map) != 0)
	{
		ft_free_check(check);
		return (-1);
	}
	ft_flood_fill(map, check->flood_map);
	i = 0;
	while (i < (map->w - 1) * map->h)
	{
		if (check->flood_map[i] == 3)
		{
			if (check->flood_map[i + 1] == 2)
				break;
			else if (check->flood_map[i - 1] == 2)
				break;
			else if (check->flood_map[i - (map->w - 1)] == 2)
				break;
			else if (check->flood_map[i + (map->w - 1)] == 2)
				break;
			return (ft_check_error(6));
		}
		i++;
	}
	ft_free_check(check);
	return (0);
}


// show unsigned int tab check_flood --debug--
/*
unsigned int	i = 0;
ft_printf("\ncheck_flood:\n");
while (i < (map->w - 1) * map->h)
{
	if (i % (map->w - 1) == 0)
		ft_printf("\n");
	ft_printf("%d", check->flood_map[i]);
	i++;
}
*/

int	ft_check_map_border(t_map *map)
{
	t_map_node	*curr;

	curr = map->head;
	if (ft_strcountchr(curr->line, '1') != map->w - 1)
		return (ft_check_error(5));
	while (curr->next != NULL)
	{
		if (curr->next->line == NULL)
		{
			if (ft_strcountchr(curr->line, '1') != map->w - 1)
				return (ft_check_error(5));
		}
		if (curr->line[0] != '1' || curr->line[map->w - 2] != '1')
			return (ft_check_error(5));
		curr = curr->next;
	}
	return (0);
}

void	ft_flood_fill(t_map *map, unsigned int *tab)
{
	unsigned int	i;
	unsigned int	empty_left;

	while (1)
	{
		empty_left = ft_nb_of_empty(map, tab);
		i = 0;
		while (i < (map->w - 1) * map->h)
		{
			if (tab[i] == 2)
			{
				if (tab[i + 1] == 0)
					tab[i + 1] = 2;
				else if (tab[i - 1] == 0)
					tab[i - 1] = 2;
				else if (tab[i - (map->w - 1)] == 0)
					tab[i - (map->w - 1)] = 2;
				else if (tab[i + (map->w - 1)] == 0)
					tab[i + (map->w - 1)] = 2;
			}
			i++;
		}
		if (ft_nb_of_empty(map, tab) == empty_left)
			break;
	}
}

unsigned int	ft_nb_of_empty(t_map *map, unsigned int *tab)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (i < (map->w - 1) * map->h)
	{
		if (tab[i] == 0)
			count++;
		i++;
	}
	return (count);
}
