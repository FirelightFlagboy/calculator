/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:36:25 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 12:39:25 by fbenneto         ###   ########.fr       */
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

t_tree	*ft_create_tree(int type, char *val)
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
	if ((*head) && (*head)->type == INT)
	{
		node = ft_create_tree(INT, (*head)->value);
		(*head) = (*head)->next;
	}
	else if ((*head) && (*head)->type == PTH && strcmp((*head)->value, "(") == 0)
	{
		(*head) = (*head)->next;
		node = parse_sum_tree(head);
		(*head) = (*head)->next;
	}
	return (node);
}

t_tree	*parse_product_tree(t_token **token)
{
	t_tree	*high;
	t_tree	*low;
	t_tree	*branch;

	branch = NULL;
	high = parse_factor_tree(token);
	if ((*token) && (*token)->type == FACTOR)
	{
		branch = ft_create_tree(SUM, (*token)->value);
		(*token) = (*token)->next;
		low = parse_product_tree(token);
		branch->high = high;
		branch->low = low;
		return (branch);
	}
	return (high);
}

t_tree	*parse_sum_tree(t_token **token)
{
	t_tree	*high;
	t_tree	*low;
	t_tree	*branch;
	int		ct;

	branch = NULL;
	ct = 0;
	high = parse_product_tree(token);
	if ((*token) && (*token)->type == SUM)
	{
		branch = ft_create_tree(SUM, (*token)->value);
		(*token) = (*token)->next;
		low = parse_sum_tree(token);
		branch->high = high;
		branch->low = low;
		return (branch);
	}
	return (high);
}

t_tree		*parser_tree(t_token **head)
{
	t_tree	*tree;

	tree = NULL;
	tree = parse_sum_tree(head);
	return (tree);
}
