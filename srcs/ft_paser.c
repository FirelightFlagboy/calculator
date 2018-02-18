/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:05:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/18 21:33:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

int		parse_pth(t_token **head)
{
	t_token	*node;
	int		nb1;
	int		nb2;

	(void)nb2;
	node = *head;
	nb1 = 42;
	if (node->type == PTH)
	{
		//TODO
	}
	else
		nb1 = atoi(node->value);
	node = node->next;
	*head = node;
	return (nb1);
}

int		parse_factor(t_token **head)
{
	t_token	*node;
	char	*type;
	int		nb1;
	int		nb2;

	nb1 = parse_pth(head);
	node = *head;
	while (node->type == FACTOR)
	{
		type = node->value;
		node = node->next;
		nb2 = parse_pth(&node);
		if (strcmp(type, "*") == 0)
			nb1 = nb1 * nb2;
		else if (strcmp(type, "/"));
			nb1 = nb1 / nb2;
	}
	*head = node;
	return (nb1);
}

int		parse_sum(t_token *head)
{
	int		nb1;
	int		nb2;
	char	*type;

	nb1 = parse_factor(&head);
	while (head->type == SUM)
	{
		type = head->value;
		head = head->next;
		nb2 = parse_factor(&head);
		if (strcmp(type, "+") == 0)
			nb1 = nb1 + nb2;
		else if (strcmp(type, "-") == 0)
			nb1 = nb1 - nb2;
	}
	return (nb1);
}
