/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:30:40 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 15:13:33 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_start_end(char *map)
{
	int	idx;

	if (map[0] != '1')
		return (0);
	idx = 0;
	while (map[idx])
		idx ++;
	if (map[idx - 2] != '1')
		return (0);
	return (-1);
}

int	check_wall(char **map, int idx)
{
	while (map[idx])
	{
		if (idx == 0)
		{
			if (indexof4(map[0], '1') != -1)
				return (0);
		}
		else if (idx != 0 && map[idx] != NULL)
		{
			if (check_start_end(map[idx]) != -1)
				return (0);
		}
		idx ++;
	}
	if (indexof4(map[idx - 1], '1') != -1)
		return (0);
	return (1);
}

int	check_nullb(char **map)
{
	int	idx;
	int	idx1;
	int	check;

	idx = 0;
	idx1 = 0;
	check = 0;
	while (map[idx])
	{
		idx1 = 0;
		while (map[idx][idx1])
			idx1 ++;
		if (check == 0)
			check = idx1;
		if (idx1 != check)
			return (0);
		idx ++;
	}
	return (1);
}

int	check_content(char **map)
{
	int		idx;
	t_comp	comp;

	idx = -1;
	comp.player = 0;
	comp.exit = 0;
	comp.collect = 0;
	while (map[++idx])
	{
		comp.player = comp.player + indexof1(map, 'P', idx);
		comp.exit = comp.exit + indexof1(map, 'E', idx);
		comp.collect = comp.collect + indexof1(map, 'C', idx);
	}
	if (comp.player != 1 || comp.exit != 1 || comp.collect == 0)
		return (0);
	return (1);
}

char	**is_map_valid(char **map)
{
	int	idx;
	int	idx1;

	if (check_nullb(map) == 0)
		return (0);
	idx = 0;
	if (check_wall(map, idx) == 0)
		return (0);
	if (check_content(map) == 0)
		return (0);
	idx = -1;
	idx1 = -1;
	while (map[++idx])
	{
		while (map[idx][++idx1])
			if (indexof2("1CEP0\n", map[idx][idx1]) != 1)
				return (0);
		idx1 = -1;
	}
	return (map);
}
