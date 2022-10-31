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
