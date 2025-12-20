/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:34:56 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 18:52:48 by mabenois         ###   ########.fr       */
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
	return (0);
}

t_check	*ft_new_check(void)
{
	t_check	*check;

	check = malloc(sizeof(t_check));
	if (!check)
		return (NULL);
	check->exit = 0;
	check->start = 0;
	check->collectible = 0;
	return (check);
}

int	ft_check_map(t_map *map)
{
	t_map_node	*curr;
	t_check		*check;

	check = ft_new_check();
	if (!check)
		return (4);
	curr = map->head;
	while (curr->next != NULL)
	{
		if (ft_strlen_gnl(curr->line) != map->w)
			return (1);
		check->exit += ft_strcountchr(curr->line, 'E');
		check->start += ft_strcountchr(curr->line, 'P');
		check->collectible += ft_strcountchr(curr->line, 'C');
		curr = curr->next;
	}
	if (check->exit != 1 || check->start != 1)
		return (2);
	if (check->collectible < 1)
		return (3);
	free(check);
	return (0);
}

int	ft_check_error(int i)
{
	if (i == 1)
		ft_printf("test");
	return (i);
}
