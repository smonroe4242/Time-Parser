/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getajob.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 06:31:04 by smonroe           #+#    #+#             */
/*   Updated: 2018/12/28 06:40:55 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETAJOB_H
# define GETAJOB_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <regex.h>
# include "libft/libft.h"

# define NUM_MATCH 2
# define ERR_SIZE 256
# define THRESHOLD 20

typedef struct		s_link
{
	char 			*early;
	char 			*later;
	struct s_link 	*next;	
}					t_link;


t_link			*new_node(char *, char *);
void			print_list(t_link *);

void			error_reg(regex_t *, int);
char			**match(regex_t *, char *);

void			parse_line(char *, t_link **, regex_t *);
void			parse_file(char *, regex_t *, regex_t *);

#endif
