/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:13:46 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/15 22:17:41 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_stock_pieces(char *str_pieces);
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

t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_liste_size(t_list *lst);
void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putnbr(int n);
void				ft_putchar(char c);

int					ft_strlen(char *str);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
