/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getajob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <scmonroe96@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 20:59:38 by smonroe           #+#    #+#             */
/*   Updated: 2018/12/28 05:22:07 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <regex.h>
#include "libft/libft.h"
#define NUM_MATCH 2
#define ERR_SIZE 256
#define THRESHOLD 20
#define BITSWAP(x, y) (((x) ^= (y)) ((y)^= (x)) ((x) ^= (y)))

struct				s_node
{
	char 			*early;
	char 			*later;
	struct s_node 	*next;	
};

struct s_node *new_node(char *early, char *later)
{
	struct s_node *tmp = (struct s_node *)malloc(sizeof(struct s_node));
	tmp->early = strdup(early);
	tmp->later = strdup(later);
	tmp->next = 0;
	return tmp;
}

void	print_list(struct s_node *node)
{
	if (!node)
		return ;
	printf("[%s]\n", node->early);
	print_list(node->next);
	printf("[%s]\n", node->later);
	free(node->early);
	free(node->later);
	free(node);
}

void	error_reg(regex_t *re, int errcode)
{
	char errbuf[ERR_SIZE];

	regerror(errcode | REG_ITOA, re, errbuf, ERR_SIZE);
	printf("[%s]\n", errbuf);
	regerror(errcode, re, errbuf, ERR_SIZE);
	printf("[%s]\n", errbuf);
}
/*
char **order(char **m)
{
	//get raw time value, compare, swap if needed, return.
}
*/
char	**match(regex_t *re, char *line)
{
	int			status = 0;
	char		**matches = 0;
	int			diff = 0;
	regmatch_t	pm[NUM_MATCH];

	matches = (char **)malloc(sizeof(char *) * (NUM_MATCH + 1));
	matches[NUM_MATCH] = 0;
	for (int i = 0; i < NUM_MATCH; i++) {
		status = regexec(re, line, NUM_MATCH, pm, 0);
		if (status) {
			error_reg(re, status);
			return 0;
		}
		diff = pm[0].rm_eo - pm[0].rm_so;
		if (!(matches[i] = (char *)malloc(sizeof(char) * (diff + 1))))
			return 0;
		line += pm[0].rm_so;
		for (int j = 0; j < diff; j++)
			matches[i][j] = *line++;
		matches[i][diff] = 0;
	}
	return (matches);
}

void	parse_line(char *line, struct s_node **head, regex_t *re)
{
	//find early:late, fill struct, and append to list
	struct s_node	*tmp = *head;
	char			**matches = 0;

	if (!line)
		return ;
	if (!(matches = match(re, line))) {
		printf("Oh no!\n");
		return ;
	}
	if (!tmp)
		*head = new_node(matches[0], matches[1]);
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node(matches[0], matches[1]);
	}
	free(line);
	for (int i = 0; i < NUM_MATCH; i++)
		free(matches[i]);
	free(matches);
}

void	parse_file(char *file, regex_t *iso, regex_t *std)
{
	int		fd = -1;
	char	*line = 0;
	struct s_node *head = 0;

	if (!file)
		return ;
	if ((fd = open(file, O_RDONLY)) == -1) {
		printf("Error while opening file %s\n", file);
		return ;
	}
	while (get_next_line(fd, &line) > 0)
		parse_line(line, &head, (strlen(line) > THRESHOLD) ? iso : std);
	print_list(head);
}

int		main(int ac, char **av)
{
	int status = 0;
	regex_t iso, std;

	if (ac < 2)
		printf("Usage: ./time-report [input files]\n");
	else
	{
		status = regcomp(&iso, "([0-9]{4}-[0-9]{1,2}-[0-9]{1,2} [0-9]{1,2}:[0-9]{2})", REG_EXTENDED);
		if (status) {
			error_reg(&iso, status);
			return 1;
		}
		status = regcomp(&std, "([0-9]{1,2}:[0-9]{2}){1}( [ap]m)?", REG_EXTENDED);
		if (status) {
			error_reg(&std, status);
			return 1;
		}
		for (int i = 1; i < ac; i++)
			parse_file(av[i], &iso, &std);
		regfree(&std);
		regfree(&iso);
	}
	return (0);
}
