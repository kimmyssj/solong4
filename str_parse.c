/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:06:39 by seungjki          #+#    #+#             */
/*   Updated: 2022/10/31 12:26:43 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	gae_haeng_check(int fd)
{
	int		idx;
	int		check;
	int		gae_haeng_gaet_su;
	char	buff[BUFFER_SIZE + 1];

	gae_haeng_gaet_su = 0;
	idx = -1;
	while (1)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == 0)
			break ;
		if (check == -1)
			return (0);
		buff[check] = '\0';
		while (buff[++idx])
			if (buff[idx] == '\n')
				gae_haeng_gaet_su ++;
		idx = -1;
	}
	return (gae_haeng_gaet_su);
}

int	gae_haeng_hwak_in(char *argv, int *fd)
{
	t_str_num	str_num;

	str_num.relative_path = malloc(sizeof(char) * (ft_strlen(argv) + 3));
	if (str_num.relative_path == NULL)
		return (0);
	str_num.relative_path[0] = '.';
	str_num.relative_path[1] = '/';
	ft_strcpy(str_num.relative_path, argv);
	*fd = open(str_num.relative_path, O_RDONLY);
	if (*fd == -1)
	{
		free(str_num.relative_path);
		return (0);
	}
	str_num.gae_haeng_gaet_su = gae_haeng_check(*fd);
	if (str_num.gae_haeng_gaet_su == 0)
	{
		free(str_num.relative_path);
		return (0);
	}
	*fd = open(str_num.relative_path, O_RDONLY);
	free(str_num.relative_path);
	return (str_num.gae_haeng_gaet_su);
}

char	**gnl_loop(char **answer, int gae_haeng_gaet_su, int fd)
{
	int	idx;

	idx = 0;
	while (idx < gae_haeng_gaet_su)
	{
		answer[idx] = get_next_line(fd);
		if (answer[idx] == 0)
		{
			while (idx > 0)
			{
				free(answer[idx - 1]);
				idx --;
			}
			return (0);
		}
		idx ++;
	}
	return (answer);
}

char	**make_it_double_array(char *argv)
{
	int		gae_haeng_gaet_su;
	int		fd;
	char	**answer;

	fd = 0;
	gae_haeng_gaet_su = gae_haeng_hwak_in(argv, &fd);
	if (gae_haeng_gaet_su == 0)
		return (NULL);
	answer = malloc(sizeof(char *) * gae_haeng_gaet_su + 1);
	if (answer == 0)
		return (NULL);
	answer[gae_haeng_gaet_su] = NULL;
	if (gnl_loop(answer, gae_haeng_gaet_su, fd) == NULL)
	{
		free(answer);
		return (NULL);
	}
	return (answer);
}
