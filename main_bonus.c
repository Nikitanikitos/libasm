/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 11:12:46 by imicah            #+#    #+#             */
/*   Updated: 2020/09/02 11:12:48 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	if (!(element = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	element->data = content;
	element->next = NULL;
	return (element);
}

void	ft_print_list(t_list *list)
{
	t_list	*temp_list;

	temp_list = list;
	while (temp_list)
	{
		printf("%s -> \n", temp_list->data);
		temp_list = temp_list->next;
	}
}

//void	test_list_size()
//{
//	t_list	*list;
//
//	list = ft_lstnew("First Element");
//
//	test_case_list_size();
//}

void	test_case_push_front(t_list *list, t_list *new)
{
	printf("Before push front\n");
	ft_print_list(list);
	ft_list_push_front(&list, new);
	printf("After push front\n");
	ft_print_list(list);
	printf("\n");
}

void	test_push_front()
{
	t_list	*list;

	list = ft_lstnew("First Element");
	printf("========== ft_list_push_front ==========\n");
	test_case_push_front(list, ft_lstnew("Push front"));
	test_case_push_front(list, ft_lstnew("Push front again"));
	printf("\n\n");
}


int 	main(void)
{
//	test_list_size();
	test_push_front();
}