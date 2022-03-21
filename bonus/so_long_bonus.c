/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:34:56 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/17 18:14:58 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_list	*root;
	t_all	all;
	t_enemy	enemy;

	enemy.dir = 1;
	root = NULL;
	all.map = &map;
	all.root = root;
	all.enemy = &enemy;
	reset_map(&map);
	if (ac == 2 && check_name(av[1]))
	{
		read_line(av[1], &all);
		render(&all);
	}
}
