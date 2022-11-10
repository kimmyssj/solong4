/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:09:13 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 15:53:56 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 500

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_gnl
{
	char	*str;
	char	buff[BUFFER_SIZE + 1];
	int		endl;
	int		size;
	char	*ret;
}	t_gnl;

typedef struct s_img
{
	void	*exit;
	void	*wall;
	void	*floor;
	void	*character;
	void	*edible;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		c_count;
	int		move;
	int		keycode;
	char	**map;
}	t_mlx;

typedef struct s_both
{
	t_img	img;
	t_mlx	*mlx;
}	t_both;

typedef struct s_str_num
{
	int		gae_haeng_gaet_su;
	char	*relative_path;
}	t_str_num;

typedef struct s_component
{
	int	player;
	int	exit;
	int	collect;
}	t_comp;

typedef struct s_image_idx
{
	int	x;
	int	y;
	int	idx;
	int	idx1;
}	t_image_idx;

typedef struct s_hook
{
	int		idx;
	int		idx1;
	char	*temp;
}	t_hook;

typedef struct s_axis
{
	int	x_p;
	int	y_p;
	int	x_e;
	int	y_e;
	int	cc;
}	t_axis;

typedef struct s_caxis
{
	int	x_c;
	int	y_c;
}	t_caxis;

typedef struct s_plague
{
	int	x;
	int	y;
	int	flag;
}	t_plague;

int		ft_strlen(char *str);
int		ber_hwak_in(char *name_of_deb);
int		initialize_everything(void **mlx, t_img *img, char *name_of_ber);
int		map_making(t_mlx *mlx, t_img img);
int		indexof(char *str, char c);
int		indexof1(char **str, char c, int idx);
int		indexof2(char *str, char c);
int		indexof3(char *str, char c);
int		indexof4(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcpy(char *dst, char *src);
int		left_is_pressed(t_mlx *mlx, t_img img);
int		down_is_pressed(t_mlx *mlx, t_img img);
int		right_is_pressed(t_mlx *mlx, t_img img);
int		up_is_pressed(t_mlx *mlx, t_img img);
int		map_path_valid(char **map);
void	plague_active(char **map, int idx);
void	free_all(char ***str);
void	image_put_in(t_mlx *mlx, char **map, t_img img);
char	*ft_strdup(char *s1);
char	**pointer(char **a);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
char	**make_it_double_array(char *argv);
char	**is_map_valid(char **map);

#endif
