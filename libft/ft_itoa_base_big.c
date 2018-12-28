/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:09:29 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/27 17:10:43 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_big(int64_t nbr, unsigned int base, char b)
{
	char	*s;
	char	*c;
	int		i;
	int64_t	n;

	if (nbr == 0)
		return (ft_strdup("0"));
	c = (b == 'u') ? "0123456789ABCDEF" : "0123456789abcdef";
	n = nbr;
	s = ft_strnew(64);
	i = 0;
	s[i++] = c[ABS(n % base)];
	while (n /= base)
		s[i++] = c[ABS(n % base)];
	(nbr < 0 && base == 10) ? (s[i] = '-') : s[i];
	ft_strrev(s);
	i = 0;
	while (!s[i])
		i++;
	c = ft_strdup(&s[i]);
	free(s);
	return (c);
}
