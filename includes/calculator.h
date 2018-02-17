/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:08:47 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/17 22:12:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum	e_type
{
	NOT,
	INT,
	OPT,
	PTH,
};

typedef struct	s_tree
{
	int				type;
	int				nb;
	char			*opt;
	struct s_tree	*low;
	struct s_tree	*high;
}				t_tree;

typedef struct	s_token
{
	int				type;
	char			value[65];
	struct s_token	*next;
}				t_token;

char	*ft_read_input();
t_token	*ft_lexer();
void	ft_free_lexer();
int		ft_isdigits(int c);
#endif
