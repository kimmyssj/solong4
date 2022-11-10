/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:22:50 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 15:58:35 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	indexof(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] != c)
			return (0);
		++index;
	}
	return (-1);
}

int	indexof1(char **str, char c, int idx)
{
	int	index;
	int	check;

	index = 0;
	check = 0;
	while (str[idx][index])
	{
		if (str[idx][index] == c)
			check ++;
		index ++;
	}
	return (check);
}

int	indexof2(char *str, char c)
{
	int	index;
	int	check;

	index = 0;
	check = 0;
	while (str[index])
	{
		if (str[index] == c)
			check ++;
		index ++;
	}
	return (check);
}

int	indexof3(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		++index;
	}
	return (-1);
}

int	indexof4(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!(str[index] == c || str[index] == '\n'))
			return (0);
		++index;
	}
	return (-1);
}
