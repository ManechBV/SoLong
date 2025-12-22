/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:07:51 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 19:24:13 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
	{
		ft_printf("not enought args\n");
		return (-1);
	}
	if (ft_init_vars(&vars) == -1)
	{
		ft_destroy_vars(&vars);
		return (-1);
	}
	vars.map = read_map(av[1]);
	if (vars.map == NULL)
	{
		ft_destroy_vars(&vars);
		return (-1);
	}
	if (ft_check_map(vars.map) == 0)
		mlx_loop(vars.mlx);
	ft_destroy_vars(&vars);
	free_map(vars.map);
	return (0);
}

/* affiche la map --debug--
   t_map_node	*curr = vars.map->head;
   while (curr->next != NULL)
   {
   ft_printf("%s", curr->line);
   curr = curr->next;
   }
 */
