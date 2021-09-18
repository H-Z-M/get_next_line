/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:04:47 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/07 04:41:30 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	safe_free(void *p)
{
	free(p);
	p = NULL;
}

char	*gnl_isnewline(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*start;

	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (NULL);
	start = newstr;
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (start);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	slen;
	int		len;
	char	*copy;
	char	*ptr;

	slen = ft_strlen(s);
	if (slen < n)
		len = slen;
	else
		len = n;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	copy = ptr;
	while (len--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (copy);
}
