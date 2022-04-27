/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:32:30 by bdurmus           #+#    #+#             */
/*   Updated: 2022/02/10 11:55:51 by bdurmus          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i + k] == needle[k] && (i + k) < len)
		{
			if (haystack[i + k] == '\0' && needle[k] == '\0')
				return ((char *)&haystack[i]);
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
