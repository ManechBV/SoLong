/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:34:56 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/26 16:38:26 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_check.h"

unsigned int	ft_strcountchr(char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_check	*ft_new_check(t_map *map)
{
	t_check			*check;

	check = malloc(sizeof(t_check));
	if (!check || map->w < 1)
		return (NULL);
	check->exit = 0;
	check->start = 0;
	check->collectible = 0;
	check->flood_map = malloc(sizeof(unsigned int) * ((map->w - 1) * map->h));
	if (!check->flood_map)
	{
		free(check);
		return (NULL);
	}
	ft_copy_map_to_int(check->flood_map, map);
	return (check);
}

void	ft_free_check(t_check *check)
{
	free(check->flood_map);
	free(check);
}

int	ft_check_map(t_map *map, t_check *check)
{
	t_map_node	*curr;

	if (!check)
		return (ft_check_error(4));
	curr = map->head;
	while (curr->next != NULL)
	{
		if (ft_strlen_gnl(curr->line) != map->w)
			return (ft_check_error(1));
		check->exit += ft_strcountchr(curr->line, 'E');
		check->start += ft_strcountchr(curr->line, 'P');
		check->collectible += ft_strcountchr(curr->line, 'C');
		curr = curr->next;
	}
	if (check->exit != 1 || check->start != 1)
		return (ft_check_error(2));
	if (check->collectible < 1)
		return (ft_check_error(3));
	return (0);
}

int	ft_check_error(int i)
{
	if (i == 1)
		ft_printf("Error\nThe map must be rectangular.\n");
	if (i == 2)
		ft_printf("Error\nThe map must contain exactly 1 exit and 1 starting position.\n");
	if (i == 3)
		ft_printf("Error\nThe map must contain at least 1 collectible.\n");
	if (i == 4)
		ft_printf("Error\nmalloc() in ft_new_check() failed Aww maaaan!\n");
	return (i);
}
