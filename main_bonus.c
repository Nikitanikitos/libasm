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
		printf("%s -> ", temp_list->data);
		temp_list = temp_list->next;
	}
	printf("\n");
}

void	test_case_list_size(t_list *list)
{
	int		size;

	size = ft_list_size(list);
	ft_print_list(list);
	printf("List size = %d\n", size);
}

void	test_list_size()
{
	t_list	*list;

	list = NULL;
	printf("========== ft_lstsize ==========\n");
	test_case_list_size(list);
	list = ft_lstnew("First Element");
	ft_list_push_back(&list, ft_lstnew("Second Element"));
	ft_list_push_back(&list, ft_lstnew("Third Element"));
	test_case_list_size(list);
	ft_list_push_back(&list, ft_lstnew("Fourth Element"));
	ft_list_push_back(&list, ft_lstnew("Fifth Element"));
	test_case_list_size(list);
	printf("\n\n");
}

void	test_case_push_front(t_list **list, t_list *new)
{
	printf("Before push front\n");
	ft_print_list(*list);
	ft_list_push_front(list, new);
	printf("After push front\n");
	ft_print_list(*list);
	printf("\n");
}

void	test_push_front()
{
	t_list	*list;

	list = ft_lstnew("First Element");
	printf("========== ft_list_push_front ==========\n");
	test_case_push_front(&list, ft_lstnew("Push front"));
	test_case_push_front(&list, ft_lstnew("Push front again"));
	test_case_push_front(&list, ft_lstnew("First element"));
	printf("\n\n");
}

void	test_case_push_back(t_list **list, t_list *new)
{
	printf("Before push back\n");
	ft_print_list(*list);
	ft_list_push_back(list, new);
	printf("After push back\n");
	ft_print_list(*list);
	printf("\n");
}

void	test_push_back()
{
	t_list	*list;

	list = ft_lstnew("First Element");
	printf("========== ft_list_push_back ==========\n");
	test_case_push_back(&list, ft_lstnew("Push back"));
	test_case_push_back(&list, ft_lstnew("Push back again"));
	test_case_push_back(&list, ft_lstnew("Last element"));
	printf("\n\n");
}

int 	main(void)
{
	test_push_front();
	test_push_back();
	test_list_size();
}
