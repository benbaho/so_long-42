/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:23:02 by bdurmus           #+#    #+#             */
/*   Updated: 2022/02/02 16:59:11 by bdurmus           ###   ########.tr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	first;
	size_t	total;

	first = ft_strlen(s1) + 1;
	total = ft_strlen(s2) + first;
	new = (char *)malloc(total * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, first);
	ft_strlcat(new, s2, total);
	return (new);
}
