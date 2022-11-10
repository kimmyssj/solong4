/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:06:34 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 15:22:41 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	img_converter(t_mlx *mlx, char component, t_img img, t_image_idx idx)
{
	if (component == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.wall, idx.x, idx.y);
	else if (component == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.floor, idx.x, idx.y);
	else if (component == 'P')
	{
		mlx_put_image_to_window(mlx->mlx,
			mlx->win, img.character, idx.x, idx.y);
		mlx->x = idx.x / 32;
		mlx->y = idx.y / 32;
	}
	else if (component == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.exit, idx.x, idx.y);
	else
	{
		mlx->c_count ++;
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.edible, idx.x, idx.y);
	}
}

void	image_put_in(t_mlx *mlx, char **map, t_img img)
{
	t_image_idx	idx;

	idx.x = 0;
	idx.y = 0;
	idx.idx = 0;
	idx.idx1 = 0;
	while (map[idx.idx])
	{
		while (map[idx.idx][idx.idx1] != '\n')
		{
			img_converter(mlx, map[idx.idx][idx.idx1], img, idx);
			idx.x = idx.x + 32;
			idx.idx1 ++;
		}
		idx.idx ++;
		idx.idx1 = 0;
		idx.x = 0;
		idx.y = idx.y + 32;
	}
}

int	map_making(t_mlx *mlx, t_img img)
{
	int	width;
	int	height;

	height = 0;
	mlx->c_count = 0;
	while (mlx->map[height])
		height ++;
	width = ft_strlen(mlx->map[0]) - 1;
	mlx->win = mlx_new_window(mlx->mlx, width * 32, height * 32, "so_long");
	if (mlx->win == 0)
	{
		write(2, "mlx_new_window fail", 20);
		return (0);
	}
	if (mlx_new_image(mlx->mlx, width * 32, height * 32) == 0)
	{
		write(2, "mlx_new_image fail", 19);
		return (0);
	}
	image_put_in(mlx, mlx->map, img);
	return (1);
}
