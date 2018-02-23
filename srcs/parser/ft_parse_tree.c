/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:36:25 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/23 21:56:04 by fbenneto         ###   ########.fr       */
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

int			search_input_tree(t_token **head, int type)
{
	t_token	*node;
	int		index;

	node = *head;
	index = 0;
	while (node)
	{
		if (node->type == type)
			return (index);
		else if (node->type != INT)
			break;
		node = node->next;
		index++;
	}
	return (-1);
}

// void		parse_factor_tree(t_token **head, t_tree **tree)
// {
// }

// void		parse_product_tree(t_token **head, t_tree **tree)
// {
// }

tree	*parse_sum_tree(t_token **head)
{
	t_tree	*node;
	t_token	*t_right;
	t_token	*t_left;
	int		index;

	index = search_input_tree(head, SUM);
	cut_input(*head, &t_left, &t_right, index);
	node = 
}

t_tree		*parser_tree(t_token **head)
{
	t_tree	*tree;

	tree = parse_sum_tree(head);
	tree = NULL;
	return (tree);
}
