/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:38:30 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 12:55:09 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	plague_initialize(char **map, int x, int y)
{
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		map[y + 1][x] = '2';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		map[y - 1][x] = '2';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		map[y][x + 1] = '2';
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		map[y][x - 1] = '2';
}

void	plague_component(char **map, t_plague *p)
{
	if ((map[p->y + 1][p->x] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y - 1][p->x] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y][p->x + 1] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y][p->x - 1] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y + 1][p->x] == '2' && map[p->y][p->x] == 'C') ||
		(map[p->y - 1][p->x] == '2' && map[p->y][p->x] == 'C') ||
		(map[p->y][p->x + 1] == '2' && map[p->y][p->x] == 'C') ||
		(map[p->y][p->x - 1] == '2' && map[p->y][p->x] == 'C'))
		{
			p->flag = 0;
			map[p->y][p->x] = '2';
		}
}

void	plague_active(char **map, int idx)
{
	t_plague	p;

	p.flag = 0;
	while (p.flag == 0)
	{
		p.y = 0;
		p.flag = 1;
		while (++p.y < idx - 1)
		{
			p.x = 0;
			while (map[p.y][++p.x] != '\n')
				plague_component(map, &p);
		}
	}
}

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
		if (!((map[caxis[idx].y_c + 1][caxis[idx].x_c] == '2') ||
			(map[caxis[idx].y_c - 1][caxis[idx].x_c] == '2') ||
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
	plague_active(mmap, idx); // this one over here
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
