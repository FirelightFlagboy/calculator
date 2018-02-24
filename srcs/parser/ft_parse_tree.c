/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:36:25 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 11:28:50 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

/*
** 2*3+4*5:
**      +
**    /  \
**   *    *
**  /\  /\
**  2 3 4 5
*/

t_tree	*ft_tree_create(int type, char *val)
{
	t_tree	*node;

	dprintf(2, "create token : ty : %d : val : %s\n", type, val);
	if (!(node = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	node->type = type;
	node->val = val;
	node->high = NULL;
	node->low = NULL;
	return (node);
}

t_tree	*parse_factor_tree(t_token **head)
{
	t_tree	*node;

	node = NULL;
	dprintf(2, "enter in parse_factor_tree\n");
	if ((*head)->type == INT)
	{
		node = ft_tree_create(INT, (*head)->value);
		(*head) = (*head)->next;
	}
	else if ((*head)->type == PTH && strcmp((*head)->value, "(") == 0)
	{
		(*head) = (*head)->next;
		node = parse_sum_tree(head);
		(*head) = (*head)->next;
	}
	dprintf(2, "\tparse_factor_tree return: adr : %p", node);
	if (node)
		dprintf(2, " : val : %s", node->val);
	dprintf(2, "\n");
	return (node);
}

// void		parse_product_tree(t_token **head, t_tree **tree)
// {
// }

t_tree	*parse_sum_tree(t_token **token)
{
	t_tree	*high;
	t_tree	*low;
	t_tree	*branch;
	t_tree	*head;

	head = NULL;
	branch = NULL;
	high = parse_factor_tree(token);
	if ((*token)->type == SUM)
	{
		branch = ft_tree_create(SUM, (*token)->value);
		if (head == NULL)
			head = branch;
		(*token) = (*token)->next;
		low = parse_factor_tree(token);
		branch->high = high;
		branch->low = low;
	}
	return (head);
}

t_tree		*parser_tree(t_token **head)
{
	t_tree	*tree;

	tree = NULL;
	tree = parse_sum_tree(head);
	return (tree);
}
