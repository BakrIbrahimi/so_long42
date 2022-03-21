/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:58:07 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/14 17:37:39 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_list	*root;
	t_all	all;

	root = NULL;
	all.map = &map;
	all.root = root;
	reset_map(&map);
	if (ac == 2 && check_name(av[1]))
	{
		read_line(av[1], &all);
		render(&all);
	}
}
