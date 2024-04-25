/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:40:08 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:17:46 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (s2)
	{
		if (!s1)
			return (0);
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(ft_strlen(s) * sizeof * str + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (char *)s, (ft_strlen((char *)s) + 1));
	return (str);
}

int	ft_strlcpy(char *str, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (src[size] != '\0')
	{
		size++;
	}
	if (n)
	{
		while (src[i] != '\0' && i < n - 1)
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		length;
	size_t		i;
	char		*dest;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1);
	length += ft_strlen(s2);
	dest = malloc(sizeof(char *) * (length));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < length)
	{
		dest[i] = *s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
