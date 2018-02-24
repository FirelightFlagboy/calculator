/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:29:32 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 14:00:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

int		eval_tree_product(t_tree *tree)
{
	int		tmp;
	
	if (strcmp(tree->val, "*") == 0)
		return (eval_tree(tree->high) * eval_tree(tree->low));
	else if (strcmp(tree->val, "/") == 0)
	{
		tmp = eval_tree(tree->low);
		if (tmp != 0)
			return (eval_tree(tree->high) / tmp);
		dprintf(2, "error can't divide by 0, now divide by 1\n");
		return (eval_tree(tree->high) / 1);
	}
	return (0);
}

int		eval_tree_sum(t_tree *tree)
{
	if (strcmp(tree->val, "+") == 0)
		return (eval_tree(tree->high) + eval_tree(tree->low));
	else if (strcmp(tree->val, "-") == 0)
		return (eval_tree(tree->high) + eval_tree(tree->low));
	return (0);
}

int		eval_tree(t_tree *tree)
{
	if (tree == NULL)
		return (0);
	printf("tree : %s : %d\n", tree->val, tree->type);
	if (tree->type == INT)
	{
		printf("\ttree : int\n");
		return (atoi(tree->val));
	}
	if (tree->type == SUM)
	{
		printf("\ttree : sum\n");
		return (eval_tree_sum(tree));
	}
	if (tree->type == FACTOR)
	{
		printf("\ttree : product\n");
		return (eval_tree_product(tree));
	}
	return (0);
}
