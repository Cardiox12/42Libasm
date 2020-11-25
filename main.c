/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:32:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/26 00:49:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <fcntl.h>

extern ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
extern size_t	ft_strlen(const char *s);
extern int	ft_strcmp(const char *s1, const char *s2);
extern char	*ft_strcpy(char *dst, const char *src);
extern ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
extern char	*ft_strdup(const char *s1);

#define TEST_FILE1 "./test1"
#define TEST_FILE2 "./test2"

#define SIMPLE_STR "Hello World!\n"
#define SIMPLE_LEN strlen(SIMPLE_STR)
#define EMPTY_STR ""

typedef struct {
	int first;
	int second;
}		t_pair;

#define Assert_int(expect, actual)								\
{																\
	if (actual != expect)										\
		printf("Expected : %i but got : %i\n", expect, actual);	\
}

#define Assert_str(expect, actual)								\
{																\
	if (strcmp(expect, actual) != 0)							\
		printf("Expected : %s but got : %s\n", expect, actual);	\
}

#define Assert_true(expr)											\
{																	\
	if (!(expr))													\
		printf("Assertion failed, (%s) must be true\n", #expr);		\
}

#define Assert_false(expr)											\
{																	\
	if (expr)														\
		printf("Assertion failed, (%s) must be false\n", #expr);	\
}

#define Test_Header(test)													\
{																			\
	printf("====================== %s ======================\n", test);		\
}

int	Test_write(void)
{
	t_pair pair;
	int actual;
	int expect;

	Test_Header("Write");

	// Write simple string to stdin
	expect = write(STDIN_FILENO, SIMPLE_STR, SIMPLE_LEN);
	actual = ft_write(STDIN_FILENO, SIMPLE_STR, SIMPLE_LEN);
	Assert_int(expect, actual);

	// Write empty string to stdin
	expect = write(STDIN_FILENO, EMPTY_STR, 1);
	actual = ft_write(STDIN_FILENO, EMPTY_STR, 1);
	Assert_int(expect, actual);

	// Write simple string into a file
	pair.first = open(TEST_FILE1, O_RDWR);
	if (pair.first == -1)
	{
		puts(strerror(errno));
		return (errno);
	}
	pair.second = open(TEST_FILE2, O_RDWR);
	if (pair.second == -1)
	{
		close(pair.first);
		puts(strerror(errno));
		return (errno);
	}
	expect = write(pair.first, SIMPLE_STR, SIMPLE_LEN);
	actual = ft_write(pair.second, SIMPLE_STR, SIMPLE_LEN);
	Assert_int(expect, actual);

	expect = write(pair.first, EMPTY_STR, 0);
	actual = ft_write(pair.second, EMPTY_STR, 0);
	Assert_int(expect, actual);

	close(pair.first);
	close(pair.second);
	actual = ft_write(pair.second, "", 0);
	Assert_int(-1, actual);
	Assert_true(actual == -1);
	Assert_int(EBADF, errno);
	Assert_true(errno == EBADF);
	return (0);
}

int	main(void)
{
	Test_write();
	return (0);
}
