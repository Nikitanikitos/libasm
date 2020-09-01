/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <imicah@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 20:46:49 by imicah            #+#    #+#             */
/*   Updated: 2020/08/21 20:46:50 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct		s_list
{
    void			*data;
    struct s_list	*next;
}					t_list;

int					ft_write(int fd, char *buff, int buffer_size);
int					ft_read(int fd, void *buff, int buffer_size);

int					ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);

char 				*ft_strcpy(char *dest, const char *src);
char 				*ft_strdup(char *src);

int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);