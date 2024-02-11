/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:54:46 by soutchak          #+#    #+#             */
/*   Updated: 2023/11/06 22:18:32 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s);

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s || !set)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (ft_isset(s[i], set))
		i++;
	while (ft_isset(s[len - 1], set))
		len--;
	if (len < i)
		len = i;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (i < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
