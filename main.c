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
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	test_strcpy_case(char *test_case)
{
	char	ft_buffer[25];
	char 	buffer[25];

	ft_strcpy(ft_buffer, test_case);
	strcpy(buffer, test_case);
	printf("%-15s | %15s\n", ft_buffer, buffer);
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

void 	test_case_strlen(char *test_case)
{
    size_t	ft_len;
    size_t	len;

    len = strlen(test_case);
    ft_len = ft_strlen(test_case);
    printf("Test case: %s\n", test_case);
    printf("%-10ld | %10ld\n", ft_len, len);
}

void	test_case_write(int fd, int ft_fd, int buffer_size, char *src)
{
    int 	ft_result;
    int 	result;

    ft_result = ft_write(ft_fd, src, buffer_size);
    ft_write(ft_fd, "\n", 1);
    result = write(fd, src, buffer_size);
    ft_write(fd, "\n", 1);
    printf("Test case: %s\n", src);
    printf("%-10d | %10d\n", ft_result, result);
}

void	test_case_read(int fd, int ft_fd, int buffer_size)
{
    int 	ft_result;
    int 	result;
    char	buffer[50];
    char	ft_buffer[50];

    ft_result = ft_read(ft_fd, ft_buffer, buffer_size);
    result = read(fd, buffer, buffer_size);
    ft_buffer[buffer_size] = 0;
    buffer[buffer_size] = 0;
    printf("Buffer size = %d\n", buffer_size);
    printf("%-10d | %10d\n", ft_result, result);
    printf("%-10s | %10s\n", ft_buffer, buffer);
}

void	test_case_strdup(char *test_case)
{
    char	*ft_result;
    char	*result;

    ft_result = ft_strdup(test_case);
    result = strdup(test_case);
    printf("%-15s | %15s\n", ft_result, result);
    free(result);
    free(ft_result);
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

void	test_strlen(void)
{
	printf("========== ft_strlen ==========\n");
	printf("%-10s | %10s", "ft_strlen", "strlen\n");
	test_case_strlen("");
	test_case_strlen("Hello, world!");
	test_case_strlen("\n");
	test_case_strlen("123\0123");
	printf("\n\n");
}

void	test_strcmp(void)
{
	printf("========== ft_strcmp ==========\n");
	printf("%-10s | %10s", "ft_strcmp", "strcmp\n");
	test_case_strcmp("", "");
	test_case_strcmp("Hello, World!", "Hello, World!");
	test_case_strcmp("Hella, World!", "Hello, World");
	test_case_strcmp("Hello, World!", "");
	test_case_strcmp("", "Hello, World!");
	printf("\n\n");
}

void	test_write(void)
{
	const int	fd = open("test.txt", O_RDWR);
	const int	ft_fd = open("ft_test.txt", O_RDWR);

	printf("========== ft_write ==========\n");
	printf("%-10s | %10s", "ft_write", "write\n");
	test_case_write(fd, ft_fd, 5, "Hello, world!");
	test_case_write(fd, ft_fd, 10, "Hello, world!");
	test_case_write(fd, ft_fd, 1, "");
	test_case_write(fd, ft_fd, 4, "123\n");
	test_case_write(1, 1, 19, "output to terminal\n");
	test_case_write(-1, -1, 19, "output to terminal\n");
	printf("\n\n");
	close(fd);
	close(ft_fd);
}

void	test_read(void)
{
	const int	fd = open("test.txt", O_RDWR);
	const int	ft_fd = open("ft_test.txt", O_RDWR);

	printf("========== ft_read ==========\n");
	printf("%-10s | %10s", "ft_read", "read\n");
	test_case_read(fd, ft_fd, 5);
	test_case_read(fd, ft_fd, 0);
	test_case_read(fd, ft_fd, 10);
	test_case_read(-1, -1, 7);
	printf("\n\n");
	close(fd);
	close(ft_fd);
}

void	test_strdup(void)
{
	printf("========== ft_strdup ==========\n");
	printf("%-15s | %15s", "ft_strdup", "strdup\n");
	test_case_strdup("");
	test_case_strdup("Hello, world!");
	test_case_strdup("Hello,\0 world!");
	test_case_strdup("213321");
    printf("\n\n");
}

int		main(void)
{
	test_strcpy();
	test_strlen();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	return (0);
}
