/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:38:30 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 15:55:03 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_location(t_axis *axis, char **map)
{
	int	idx;
	int	idx1;

	idx = -1;
	idx1 = -1;
	axis->cc = 0;
	while (map[++idx])
	{
		while (map[idx][++idx1])
		{
			if (map[idx][idx1] == 'P')
			{
				axis->x_p = idx1;
				axis->y_p = idx;
			}
			else if (map[idx][idx1] == 'E')
			{
				axis->x_e = idx1;
				axis->y_e = idx;
			}
			if (map[idx][idx1] == 'C')
				axis->cc ++;
		}
		idx1 = -1;
	}
}

int	is_he_weak(char **map, t_axis a, t_caxis *caxis)
{
	int	answer;
	int	idx;

	answer = 0;
	idx = 0;
	if ((map[a.y_e + 1][a.x_e] == '2') || (map[a.y_e - 1][a.x_e] == '2') ||
			(map[a.y_e][a.x_e + 1] == '2') || (map[a.y_e][a.x_e - 1] == '2'))
		answer = 1;
	while (idx < a.cc)
	{
		if (!((map[caxis[idx].y_c + 1][caxis[idx].x_c] == '2')
			|| (map[caxis[idx].y_c - 1][caxis[idx].x_c] == '2') ||
			(map[caxis[idx].y_c][caxis[idx].x_c + 1] == '2') ||
			(map[caxis[idx].y_c][caxis[idx].x_c - 1] == '2')))
			return (0);
		idx ++;
	}
	return (answer);
}

t_caxis	*c_location(t_caxis *caxis, char **map, int cc)
{
	int	idx;
	int	idx1;
	int	idx2;

	idx = 0;
	idx1 = 0;
	idx2 = 0;
	caxis = malloc(sizeof(t_caxis) * (cc));
	if (caxis == 0)
		return (0);
	while (map[++idx])
	{
		while (map[idx][++idx1])
		{
			if (map[idx][idx1] == 'C')
			{
				caxis[idx2].x_c = idx1;
				caxis[idx2].y_c = idx;
				idx2 ++;
			}
		}
		idx1 = 0;
	}
	return (caxis);
}

int	map_path_valid(char **map)
{
	t_axis	axis;
	char	**mmap;
	t_caxis	*caxis;
	int		idx;

	idx = 0;
	caxis = 0;
	mmap = pointer(map);
	if (mmap == 0)
		return (0);
	while (mmap[idx])
		idx ++;
	check_location(&axis, mmap);
	caxis = c_location(caxis, map, axis.cc);
	plague_initialize(mmap, axis.x_p, axis.y_p);
	plague_active(mmap, idx);
	if (is_he_weak(mmap, axis, caxis) == 0)
	{
		free(caxis);
		free_all(&mmap);
		return (0);
	}
	free_all(&mmap);
	free(caxis);
	return (1);
}
