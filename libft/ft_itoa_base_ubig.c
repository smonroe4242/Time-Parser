/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ubig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:11:24 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/27 17:12:38 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_ubig(uint64_t nbr, unsigned int base, char b)
{
	char		*s;
	char		*c;
	int			i;
	uint64_t	n;

	if (nbr == 0)
		return (ft_strdup("0"));
	c = (b == 'u') ? "0123456789ABCDEF" : "0123456789abcdef";
	n = nbr;
	s = ft_strnew(64);
	i = 0;
	s[i++] = c[n % base];
	while (n /= base)
		s[i++] = c[n % base];
	ft_strrev(s);
	i = 0;
	while (!s[i])
		i++;
	c = ft_strdup(&s[i]);
	free(s);
	return (c);
}
