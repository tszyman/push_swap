/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:03:58 by tomek             #+#    #+#             */
/*   Updated: 2024/03/12 22:31:39 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	end;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	end = 0;
	if (start < s_len)
		end = s_len - start;
	else
		return ((char *)ft_calloc((1), sizeof(char)));
	if (end > len)
		end = len;
	ret = (char *)ft_calloc((end + 1), sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, end + 1);
	return (ret);
}
