/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <smonroe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:09:55 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/27 17:26:36 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	positive(t_var v)
{
	if ((v.flag == 'd' || v.flag == 'i') && v.uni.i > -1)
		return (1);
	if (v.flag == 'D' && v.uni.l > -1)
		return (1);
	return (0);
}

static char	*prefix(t_var v)
{
	if (v.flag == 'x')
		return ("0x");
	else if (v.flag == 'X')
		return ("0X");
	else if ((v.flag == 'O' || v.flag == 'o') && v.uni.l)
		return ("0");
	else if (v.flag == 'b')
		return ("0b");
	else
		return ("");
}

static char	*printer_prec(t_var v)
{
	if (!positive(v) && v.base == 10 && v.prec >= (int)ft_strlen(v.str))
		v.str[0] = '0';
	while ((int)ft_strlen(v.str) < v.prec)
		v.str = ft_strappfr("0", v.str);
	if (!positive(v) && v.base == 10 && v.str[0] != '-')
		v.str = ft_strappfr("-", v.str);
	return (v.str);
}

char		*printer(t_var v)
{
	if (v.flag == 's')
		return (string(v));
	if (v.prec)
		v.str = printer_prec(v);
	if (v.plus && positive(v))
	{
		if (v.point == '0')
			v.str[0] = '+';
		else
			v.str = ft_strappfr("+", v.str);
	}
	if (v.hash)
		v.str = ft_strappfr(prefix(v), v.str);
	if (v.spc && !v.plus && v.str[0] != '-')
		v.str = ft_strappfr(" ", v.str);
	if (v.pad)
	{
		if (v.neg)
			while ((int)ft_strlen(v.str) < v.pad)
				v.str = ft_strjoinfr(v.str, " ");
		if (!v.neg)
			while ((int)ft_strlen(v.str) < v.pad)
				v.str = ft_strappfr(" ", v.str);
	}
	return (v.str);
}
