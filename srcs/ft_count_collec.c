/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_collec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <mabenois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:51:34 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/09 18:12:10 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_check.h"

unsigned int	ft_count_collec(t_vars *vars)
{
	t_map_node		*curr;
	unsigned int	count;

	curr = vars->map->head;
	count = 0;
	while (curr->next != NULL)
	{
		count += ft_strcountchr(curr->line, 'C');
		curr = curr->next;
	}
	return (count);
}
