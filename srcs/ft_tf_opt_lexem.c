/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tf_opt_lexem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:54:12 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/18 21:33:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

static void	ft_change_opt(t_token *node)
{
	char	*pth[] = {"(", ")", NULL};
	char	*fac[] = {"*", "/", NULL};
	char	*sum[] = {"+", "-", NULL};
	int		i;

	i = -1;
	while (sum[++i])
		if (strncmp(sum[i], node->value, strlen(sum[i])) == 0\
		&& (node->type = SUM))
			return ;
	i = -1;
	while (fac[++i])
		if (strncmp(fac[i], node->value, strlen(fac[i])) == 0\
		&& (node->type = FACTOR))
			return ;
	i = -1;
	while (pth[++i])
		if (strncmp(pth[i], node->value, strlen(pth[i])) == 0\
		&& (node->type = PTH))
			return ;
}

void		ft_tf_opt_lexem(t_token **headref)
{
	t_token *node;

	node = *headref;
	while (node)
	{
		if (node->type == KWD)
			ft_change_opt(node);
		node = node->next;
	}
}
