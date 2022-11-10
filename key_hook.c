/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:38:35 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/09 17:38:36 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_exit(t_mlx *mlx, char **temp)
{
	int	idx;
	int	idx1;

	idx = 1;
	idx1 = 1;
	while (mlx->map[idx] != NULL)
	{
		while (mlx->map[0][idx1] != '\n')
		{
			if (mlx->map[idx][idx1] == 'C')
			{
				mlx->move --;
				free(*temp);
				return (0);
			}
			idx1 ++;
		}
		idx1 = 1;
		idx ++;
	}
	write(1, *temp, ft_strlen(*temp) + 1);
	free(*temp);
	return (1);
}

int	left_is_pressed(t_mlx *mlx, t_img img)
{
	char	*temp;
	int		flag;

	flag = 2;
	if (mlx->map[mlx->y][mlx->x - 1] == '1')
		return (0);
	mlx->move ++;
	temp = ft_itoa(mlx->move);
	if (temp == 0 || mlx->move == -2147483648)
		return (2);
	if (mlx->map[mlx->y][mlx->x - 1] == 'E')
		flag = check_exit(mlx, &temp);
	if (flag == 1)
		return (1);
	else if (flag == 0)
		return (0);
	mlx->map[mlx->y][mlx->x - 1] = mlx->map[mlx->y][mlx->x];
	mlx->map[mlx->y][mlx->x] = '0';
	mlx_clear_window(mlx->mlx, mlx->win);
	image_put_in(mlx, mlx->map, img);
	write(1, temp, ft_strlen(temp) + 1);
	free(temp);
	return (0);
}

int	down_is_pressed(t_mlx *mlx, t_img img)
{
	char	*temp;
	int		flag;

	flag = 2;
	if (mlx->map[mlx->y + 1][mlx->x] == '1')
		return (0);
	mlx->move ++;
	temp = ft_itoa(mlx->move);
	if (temp == 0 || mlx->move == -2147483648)
		return (2);
	if (mlx->map[mlx->y + 1][mlx->x] == 'E')
		flag = check_exit(mlx, &temp);
	if (flag == 1)
		return (1);
	else if (flag == 0)
		return (0);
	mlx->map[mlx->y + 1][mlx->x] = mlx->map[mlx->y][mlx->x];
	mlx->map[mlx->y][mlx->x] = '0';
	mlx_clear_window(mlx->mlx, mlx->win);
	image_put_in(mlx, mlx->map, img);
	write(1, temp, ft_strlen(temp) + 1);
	free(temp);
	return (0);
}

int	right_is_pressed(t_mlx *mlx, t_img img)
{
	char	*temp;
	int		flag;

	flag = 2;
	if (mlx->map[mlx->y][mlx->x + 1] == '1')
		return (0);
	mlx->move ++;
	temp = ft_itoa(mlx->move);
	if (temp == 0 || mlx->move == -2147483648)
		return (2);
	if (mlx->map[mlx->y][mlx->x + 1] == 'E')
		flag = check_exit(mlx, &temp);
	if (flag == 1)
		return (1);
	else if (flag == 0)
		return (0);
	mlx->map[mlx->y][mlx->x + 1] = mlx->map[mlx->y][mlx->x];
	mlx->map[mlx->y][mlx->x] = '0';
	mlx_clear_window(mlx->mlx, mlx->win);
	image_put_in(mlx, mlx->map, img);
	write(1, temp, ft_strlen(temp) + 1);
	free(temp);
	return (0);
}

int	up_is_pressed(t_mlx *mlx, t_img img)
{
	char	*temp;
	int		flag;

	flag = 2;
	if (mlx->map[mlx->y - 1][mlx->x] == '1')
		return (0);
	mlx->move ++;
	temp = ft_itoa(mlx->move);
	if (temp == 0 || mlx->move == -2147483648)
		return (2);
	if (mlx->map[mlx->y - 1][mlx->x] == 'E')
		flag = check_exit(mlx, &temp);
	if (flag == 1)
		return (1);
	else if (flag == 0)
		return (0);
	mlx->map[mlx->y - 1][mlx->x] = mlx->map[mlx->y][mlx->x];
	mlx->map[mlx->y][mlx->x] = '0';
	mlx_clear_window(mlx->mlx, mlx->win);
	image_put_in(mlx, mlx->map, img);
	write(1, temp, ft_strlen(temp) + 1);
	free(temp);
	return (0);
}
