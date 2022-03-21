/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:41:25 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/17 13:47:16 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reset_map(t_map *map)
{
	map->c = 0;
	map->e = 0;
	map->h = 0;
	map->w = 0;
	map->p = 0;
	map->x = 0;
	map->y = 0;
	map->in = 1;
}
