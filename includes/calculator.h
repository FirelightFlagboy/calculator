/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:08:47 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/19 22:06:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

enum	e_type
{
	NOT,
	INT,
	KWD,
	SUM,
	FACTOR,
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

/*
** Print
*/
void	ft_print_lexem(t_token *lexem);
/*
** Input
*/
char	*ft_read_input();
/*
** Lexer
*/
t_token	*ft_lexer();
void	ft_clean_lexem(t_token **headref);
void	ft_free_lexer();
void	ft_tf_opt_lexem(t_token **headref);
/*
** Parser
*/
int		parse_sum(t_token **head);
int		parse_factor(t_token **head);
int		parse_product(t_token **head);
int		parse_pth(t_token **head);
/*
** Tree
*/
void	ft_ttree_free(t_tree **head);
t_tree	*ft_ttre_create(int type, char *value, char *isneg);
/*
** ft_type
*/
int		ft_isdigits(int c);
int		ft_isspaces(int c);
#endif
