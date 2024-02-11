/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:53:38 by soutchak          #+#    #+#             */
/*   Updated: 2023/11/06 22:15:55 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	while (dest[i])
		i++;
	dlen = i;
	j = 0;
	while (src[j])
		j++;
	slen = j;
	if (dsize <= dlen)
		return (dsize + slen);
	j = 0;
	while (src[j] && dlen + j < dsize - 1)
	{
		dest[dlen + j] = src[j];
		j++;
	}
	dest[dlen + j] = '\0';
	return (dlen + slen);
}
