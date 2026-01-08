/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:07:51 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/07 14:32:43 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "map_draw.h"
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

	ft_load_map_img(&vars);

	ft_printf("\nvars->map:\n");
	t_map_node	*curr = vars.map->head;
	while (curr->next != NULL)
	{
		ft_printf("%s", curr->line);
		curr = curr->next;
	}
	ft_printf("\n");
	
	if (ft_check_map_and_flood(vars.map) == 0)
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
