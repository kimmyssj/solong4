/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:06:34 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 14:16:54 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	img_converter(t_mlx *mlx, char component, t_img img, int x, int y)
{
	if (component == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.wall, x, y);
	else if (component == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.floor, x, y);
	else if (component == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.character, x, y);
		mlx->x = x / 32;
		mlx->y = y / 32;
	}
	else if (component == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.exit, x, y);
	else
	{
		mlx->c_count ++;
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.edible, x, y);	
	}
}

void	image_put_in(t_mlx *mlx, char **map, t_img img)
{
	int	x;
	int	y;
	int	idx;
	int	idx1;

	x = 0;
	y = 0;
	idx = 0;
	idx1 = 0;
	while (map[idx])
	{
		while (map[idx][idx1] != '\n')
		{
			img_converter(mlx, map[idx][idx1], img, x, y);
			x = x + 32;
			idx1 ++;
		}
		idx ++;
		idx1 = 0;
		x = 0;
		y = y + 32;
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
	width =  ft_strlen(mlx->map[0]) - 1;
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
