/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:13:46 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/19 14:56:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_piece
{
	t_pos			b1;
	t_pos			b2;
	t_pos			b3;
	t_pos			b4;
}					t_piece;

char				**ft_all(t_piece *pieces);
t_piece				*ft_stock_pieces(char *str_pieces);
char				*ft_get_pieces(char *filename);
char				**ft_get_tetri(void);
int					ft_check_shape(char *str_piece);
int					ft_check_errors(char *str_piece);
int					ft_check_nl(char nl);
int					ft_check_last_nl(char *str_pieces);
int					ft_match_pieces(char *str_piece);
int					ft_count_pieces(char *str_pieces);
int					ft_get_pattern(char *str_piece);
void				ft_print_tab(char **tab, int size);
char				**ft_resolve(t_piece *pieces);

void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putnbr(int n);
void				ft_putchar(char c);

int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
