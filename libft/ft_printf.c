/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:21:30 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/27 17:22:17 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char *str, ...)
{
	int		len;
	char	*buf;
	va_list ap;

	va_start(ap, str);
	buf = parse(str, ap);
	len = ft_strlen(buf);
	ft_putstr(buf);
	free(buf);
	va_end(ap);
	return (len);
}
