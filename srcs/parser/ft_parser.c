/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:05:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 14:10:38 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

int		parse_factor(t_token **head)
{
	int		nb1;

	nb1 = 0;
	if ((*head) && (*head)->type == INT)
	{
		nb1 = atoi((*head)->value);
		(*head) = (*head)->next;
	}
	else if ((*head) && (*head)->type == PTH && strcmp((*head)->value, "(") == 0)
	{
		(*head) = (*head)->next;
		nb1 = parse_sum(head);
		(*head) = (*head)->next;
	}
	else if ((*head) && (*head)->type == SUM && strcmp((*head)->value, "-") == 0)
	{
		(*head) = (*head)->next;
		nb1 = parse_factor(head);
		nb1 = -nb1;
	}
	return (nb1);
}
int		parse_product(t_token **head)
{
	t_token	*node;
	char	*type;
	int		nb1;
	int		nb2;

	nb1 = parse_factor(head);
	node = *head;
	while (node && node->type == FACTOR)
	{
		type = node->value;
		node = node->next;
		nb2 = parse_factor(&node);
		if (strcmp(type, "*") == 0)
			nb1 = nb1 * nb2;
		else if (strcmp(type, "/") == 0)
			nb1 = nb1 / nb2;
	}
	*head = node;
	return (nb1);
}

int		parse_sum(t_token **head)
{
	int		nb1;
	int		nb2;
	char	*type;

	nb1 = parse_product(head);
	while ((*head) && (*head)->type == SUM)
	{
		type = (*head)->value;
		(*head) = (*head)->next;
		nb2 = parse_product(head);
		if (strcmp(type, "+") == 0)
			nb1 = nb1 + nb2;
		else if (strcmp(type, "-") == 0)
			nb1 = nb1 - nb2;
	}
	return (nb1);
}
