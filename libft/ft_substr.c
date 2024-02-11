/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:54:50 by soutchak          #+#    #+#             */
/*   Updated: 2023/11/06 09:27:22 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

static size_t	ft_sublen(char const *s, unsigned int start, size_t len)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (0);
	if (start + len > slen)
		return (slen - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_sublen(s, start, len);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	if (len)
		while (s[start] && i < len)
			sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

// #include <stdio.h>
// int main()
// {
// 	char const *s = "Hello World";
// 	char *sub = ft_substr(s, 40, 30);
// 	if (!sub)
// 		return (0);
// 	printf("(%s)\n", sub);
// 	free(sub);
// 	return 0;
// }
