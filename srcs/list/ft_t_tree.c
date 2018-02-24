/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:46:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 13:53:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

void	ft_ttree_free(t_tree **head)
{
	if (head == NULL || *head == NULL)
		return ;
	if ((*head)->low)
		ft_ttree_free(&((*head)->low));
	if ((*head)->high)
		ft_ttree_free(&((*head)->high));
	free(*head);
	*head = NULL;
}
