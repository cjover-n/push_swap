/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:01:19 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/16 17:28:49 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countstr(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**affect(char const *s, char **dst, char c, int l)
{
	int	i;
	int	y;
	int	k;

	i = 0;
	y = 0;
	while (s[i] != '\0' && y < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[y] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (!dst[y])
			return (NULL);
		while (s[i] != '\0' && s[i] != c)
			dst[y][k++] = s[i++];
		dst[y][k] = '\0';
		y++;
	}
	dst[y] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		n;

	if (s == NULL)
		return (NULL);
	n = countstr(s, c);
	dst = (char **)malloc(sizeof(char *) * (n + 1));
	if (!dst)
		return (NULL);
	return (affect(s, dst, c, n));
}
