/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:18:12 by bdurmus           #+#    #+#             */
/*   Updated: 2022/02/05 11:04:37 by bdurmus           ###   ########.tr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_strdup(s);
	if (!s || !f || !str)
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
