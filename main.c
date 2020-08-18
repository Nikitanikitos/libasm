/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <imicah@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:03:32 by imicah            #+#    #+#             */
/*   Updated: 2020/08/18 16:43:21 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		ft_write(int fd, char *buff, int buffer_size);
int		ft_read(int fd, void *buff, int buffer_size);
int		ft_strlen(const char *s);
char 	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

int		main(void)
{
	int		q;
	char	buffer[10];
	char	*p;

	q = ft_strlen("halla");
//	p = ft_strcpy("Hello", buffer);
	printf("%d\n",q);
	return (0);
}
