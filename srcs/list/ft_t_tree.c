/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:46:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/22 22:03:34 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

t_tree	*ft_ttre_create(int type, char *value, char *isneg)
{
	t_tree	*node;
	int		nb;

	if (!(node = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	node->type = type;
	node->low = NULL;
	node->high = NULL;
	node->opt = NULL;
	if (type == INT)
	{
		nb = atoi(value);
		if (isneg)
			nb = -nb;
		node->nb = nb;
	}
	else
		node->opt = value;
	return (node);
}

void	ft_ttree_free(t_tree **head)
{
	// t_tree *node;

	if (head == NULL || *head == NULL)
		return ;
	if ((*head)->low)
		ft_ttree_free(&((*head)->low));
	if ((*head)->high)
		ft_ttree_free(&((*head)->high));
	free(*head);
	*head = NULL;
}
