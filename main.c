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

#include "libasm.h"
#include "stdio.h"
#include "string.h"

void	test_strcpy_case(char *test_case)
{
	char	ft_buffer[25];
	char 	buffer[25];


	ft_strcpy(ft_buffer, test_case);
	strcpy(buffer, test_case);
	printf("%-15s | %15s\n", ft_buffer, buffer);
}

void	test_strcpy(void)
{
	printf("========== ft_strcpy ==========\n");
	printf("%-15s | %15s", "ft_strcpy", "strcpy\n");
	test_strcpy_case("");
	test_strcpy_case("Hello, World!");
	test_strcpy_case(" 123\0321");
	printf("\n\n");
}

void 	test_case_strlen(char *test_case)
{
	size_t	ft_len;
	size_t	len;

	len = strlen(test_case);
	ft_len = ft_strlen(test_case);
	printf("Test case: %s\n", test_case);
	printf("%-10ld | %10ld\n", ft_len, len);
}

void	test_strlen(void)
{
	printf("========== ft_strlen ==========\n");
	printf("%-10s | %10s", "ft_strlen", "ft_strlen\n");
	test_case_strlen("");
	test_case_strlen("Hello, world!");
	test_case_strlen("\n");
	test_case_strlen("123\0123");
	printf("\n\n");
}

void	test_case_strcmp(char *array1, char *array2)
{
	int		ft_result;
	int 	result;

	result = strcmp(array1, array2);
	ft_result = ft_strcmp(array1, array2);
	printf("Test case: %s -- %s\n", array1, array2);
	printf("%-10d | %10d\n", ft_result, result);
}

void	test_strcmp(void)
{
	printf("========== ft_strcmp ==========\n");
	printf("%-10s | %10s", "ft_strcmp", "ft_strcmp\n");
	test_case_strcmp("", "");
	test_case_strcmp("Hello, World!", "Hello, World!");
	test_case_strcmp("Hello, World!", "Hella, World");
	test_case_strcmp("Hello, World!", "");
	test_case_strcmp("", "Hello, World!");
}

int		main(void)
{
	test_strcpy();
	test_strlen();
//	test_strcmp();
	return (0);
}
