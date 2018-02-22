/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:36:25 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/22 22:14:17 by fbenneto         ###   ########.fr       */
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
void		parse_factor_tree(t_token **head, t_tree **tree)
{
	t_tree *node;

	parse_product_tree(head, tree);
}

void		parse_product_tree(t_token **head, t_tree **tree)
{
	t_tree *node;

	parse_product_tree(head, tree);
}

void		parse_sum_tree(t_token **head, t_tree **tree)
{
	t_tree *node;

	parse_product_tree(head, tree);
}

t_tree		*parser_tree(t_token **head)
{
	t_tree *tree;

	parse_sum_tree(head, &tree);
	return (tree);
}
