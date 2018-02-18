/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:05:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/18 21:49:06 by fbenneto         ###   ########.fr       */
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
	int		nb1;

	nb1 = 0;
	dprintf(2, "enter in parse_factor\n");	
	if ((*head)->type == INT)
	{
		nb1 = atoi((*head)->value);
		(*head) = (*head)->next;
	}
	else
	{
		dprintf(2, "\terror not a digits %s\n", (*head)->value);
	}
	dprintf(2, "\tparse_factor return: %d\n", nb1);
	return (nb1);
}
int		parse_product(t_token **head)
{
	t_token	*node;
	char	*type;
	int		nb1;
	int		nb2;

	dprintf(2, "enter in parse_product\n");
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
	dprintf(2, "\tparse_product return: %d\n", nb1);
	return (nb1);
}

int		parse_sum(t_token *head)
{
	int		nb1;
	int		nb2;
	char	*type;

	dprintf(2, "enter in parse_sum\n");
	nb1 = parse_product(&head);
	while (node && head->type == SUM)
	{
		type = head->value;
		head = head->next;
		nb2 = parse_product(&head);
		if (strcmp(type, "+") == 0)
			nb1 = nb1 + nb2;
		else if (strcmp(type, "-") == 0)
			nb1 = nb1 - nb2;
	}
	dprintf(2, "\tin parse_sum return: %d\n", nb1);	
	return (nb1);
}
