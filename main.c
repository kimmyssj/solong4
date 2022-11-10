/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:48:42 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 15:24:33 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_all(char ***str)
{
	int	idx;

	idx = 0;
	while (str[0][idx])
	{
		free(str[0][idx]);
		idx++;
	}
	free(str[0][idx]);
	free(*str);
}

int	key_hook(int keycode, t_both *both)
{
	int	flag;

	flag = 0;
	if (keycode == 0)
		flag = left_is_pressed(both->mlx, both->img);
	else if (keycode == 1)
		flag = down_is_pressed(both->mlx, both->img);
	else if (keycode == 2)
		flag = right_is_pressed(both->mlx, both->img);
	else if (keycode == 13)
		flag = up_is_pressed(both->mlx, both->img);
	else if (keycode == 53)
		exit(0);
	if (flag == 0)
		return (0);
	else if (flag == 1)
	{
		write(1, "Congrats! You won!", 18);
		exit(0);
	}
	write(2, "Number count failed", 20);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_img	img;
	t_both	both;

	if (argc != 2)
		return (write(2, "Need only two argv", 19));
	if (initialize_everything(&mlx.mlx, &img, argv[1]))
		return (write(2, "Initialize fail", 16));
	mlx.map = make_it_double_array(argv[1]);
	if (mlx.map == 0)
		return (write(2, "Failed making double array", 27));
	if (!is_map_valid(mlx.map) || !map_path_valid(mlx.map))
		return (write(2, "Not a valid map", 16));
	if (map_making(&mlx, img) == 0)
		return (write(2, "Fail to build map", 18));
	both.mlx = &mlx;
	both.img = img;
	mlx.move = 0;
	mlx_hook(mlx.win, 2, mlx.keycode, key_hook, &both);
	mlx_loop(mlx.mlx);
}
