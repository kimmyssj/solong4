/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:09:06 by seungjki          #+#    #+#             */
/*   Updated: 2022/11/10 13:35:14 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s1[idx] == s2[idx])
		idx ++; 
	if (s1[idx] == '\0' && s2[idx] == '\0')
        return (0);
    return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

int	ft_strcpy(char *dst, char *src)
{
	int	idx;
	int	idx1;
	int	src_len;

	idx = 2;
	idx1 = 0;
	src_len = ft_strlen(src);
	while (idx1 < src_len)
	{
		dst[idx] = src[idx1];
		idx ++;
		idx1 ++;
	}
	dst[idx] = '\0';
	return (src_len);
}

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char    *ft_strdup(char *s1)
{
    int     idx;
    char    *result;

    idx = 0;
    while (s1[idx])
        idx ++;
    result = (char *)malloc(sizeof(char) * idx + 1);
    if (result == NULL)
        return (NULL);
    while (idx != -1)
    {
        result[idx] = s1[idx];
        idx --;
    }
    return (result);
}

char	**pointer(char **a)
{
	int		idx;
	char	**answer;

	idx = 0;
	while (a[idx])
		idx ++;
	answer = malloc(sizeof(char *) * idx + 1);
	if (answer == 0)
		return (0);
	answer[idx] = 0;
	idx = -1;
	while (a[++idx])
	{
		answer[idx] = ft_strdup(a[idx]);
		if (answer[idx] == 0)
			free_all(&answer);
	}
	return (answer);
}
