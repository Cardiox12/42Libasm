/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:32:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/26 12:38:45 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <fcntl.h>

extern ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dst, const char *src);
extern ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
extern char		*ft_strdup(const char *s);

#define TEST_FILE1 "./test1"
#define TEST_FILE2 "./test2"
#define BUFF_SIZE 500

#define SIMPLE_STR "Hello World!\n"
#define EMPTY_STR ""
#define LONG_STR "Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
Duis interdum odio sit amet vulputate mollis. Proin vel ligula vel nisi \
tristique dapibus ut eu leo. Aliquam leo mauris, maximus vitae dui at, \
aliquam pharetra tellus. Nullam condimentum tincidunt aliquet. Quisque \
id tortor pulvinar, fermentum turpis ut, vulputate ipsum. Donec sit amet \
consequat dolor. Duis dictum magna augue, non efficitur purus pellentesque \
scelerisque. Etiam dapibus lacus eu tristique vehicula. Cras quis massa vitae \
quam cursus lacinia. Phasellus in tincidunt ligula. Etiam sit amet posuere \
purus, eget rhoncus dui. Fusce nulla purus, congue interdum dolor vitae, \
consectetur suscipit libero."

#define LONG_STR_SIZE strlen(LONG_STR)
#define SIMPLE_STR_SIZE strlen(SIMPLE_STR)
#define EMPTY_STR_SIZE 0

typedef struct {
	int first;
	int second;
}		t_pair;

#define Assert_int(expect, actual, test)													\
{																							\
	if (actual != expect)																	\
		printf("Test: %-30s : Expected : %-10i but got : %i\n", test, expect, actual);		\
	else																					\
		printf("Test: %-30s : Success\n", test);											\
}

#define Assert_str(expect, actual, test)													\
{																							\
	if (strcmp(expect, actual) != 0)														\
		printf("Test: %-30s : Expected : %-10s but got : %s\n", test, expect, actual);		\
	else																					\
		printf("Test: %-30s : Success\n", test);											\
}

#define Assert_true(expr, test)																\
{																							\
	if (!(expr))																			\
		printf("Test: %-30s : Assertion failed, (%s) must be true\n", test, #expr);			\
	else																					\
		printf("Test: %-30s : Success\n", test);											\
}

#define Assert_false(expr, test)															\
{																							\
	if (expr)																				\
		printf("Test: %-30s : Assertion failed, (%s) must be false\n", test, #expr);		\
	else																					\
		printf("Test: %-30s : Success\n", test);											\
}

#define Test_Header(test)																	\
{																							\
	printf("====================== %s ======================\n", test);						\
}

void	Test_write(void)
{
	t_pair pair;
	int actual;
	int expect;

	Test_Header("Write");

	// Write simple string to stdin
	expect = write(STDIN_FILENO, SIMPLE_STR, SIMPLE_STR_SIZE);
	actual = ft_write(STDIN_FILENO, SIMPLE_STR, SIMPLE_STR_SIZE);
	Assert_int(expect, actual, "simple string");

	// Write empty string to stdin
	expect = write(STDIN_FILENO, EMPTY_STR, 1);
	actual = ft_write(STDIN_FILENO, EMPTY_STR, 1);
	Assert_int(expect, actual, "empty string");

	// Write simple string into a file
	pair.first = open(TEST_FILE1, O_RDWR);
	if (pair.first == -1)
	{
		puts(strerror(errno));
		return ;
	}
	pair.second = open(TEST_FILE2, O_RDWR);
	if (pair.second == -1)
	{
		close(pair.first);
		puts(strerror(errno));
		return ;
	}
	expect = write(pair.first, SIMPLE_STR, SIMPLE_STR_SIZE);
	actual = ft_write(pair.second, SIMPLE_STR, SIMPLE_STR_SIZE);
	Assert_int(expect, actual, "simple string to file");

	expect = write(pair.first, LONG_STR, LONG_STR_SIZE);
	actual = ft_write(pair.second, LONG_STR, LONG_STR_SIZE);
	Assert_int(expect, actual, "simple string to file");

	expect = write(pair.first, EMPTY_STR, 0);
	actual = ft_write(pair.second, EMPTY_STR, 0);
	Assert_int(expect, actual, "empty string to file");

	close(pair.first);
	close(pair.second);
	actual = ft_write(pair.second, "", 0);
	Assert_int(-1, actual, "closed fd");
	Assert_true(actual == -1, "closed fd");
	Assert_int(EBADF, errno, "closed fd errno");
	Assert_true(EBADF == errno, "closed fd errno");
}

void	Test_strlen(void)
{
	int actual;
	int expect;

	Test_Header("Strlen");

	// Basic test
	expect = strlen(SIMPLE_STR);
	actual = ft_strlen(SIMPLE_STR);
	Assert_int(expect, actual, "simple string");

	// Test with empty string
	expect = strlen(EMPTY_STR);
	actual = ft_strlen(EMPTY_STR);
	Assert_int(expect, actual, "empty string");

	// Test with long string
	expect = strlen(LONG_STR);
	actual = ft_strlen(LONG_STR);
	Assert_int(expect, actual, "long string");
}

void	Test_strcmp(void)
{
	int expect;
	int actual;

	Test_Header("Strcmp");

	// Equal strings
	expect = strcmp(SIMPLE_STR, SIMPLE_STR);
	actual = ft_strcmp(SIMPLE_STR, SIMPLE_STR);
	Assert_int(expect, actual, "simple equal strings");

	expect = strcmp(EMPTY_STR, EMPTY_STR);
	actual = ft_strcmp(EMPTY_STR, EMPTY_STR);
	Assert_int(expect, actual, "empty equal strings");

	expect = strcmp(LONG_STR, LONG_STR);
	actual = ft_strcmp(LONG_STR, LONG_STR);
	Assert_int(expect, actual, "long equal strings");

	// First string not equal
	actual = ft_strcmp(EMPTY_STR, SIMPLE_STR);
	Assert_true(actual < 0, "empty / simple strings");

	actual = ft_strcmp(LONG_STR, SIMPLE_STR);
	Assert_true(actual > 0, "long / simple strings");

	actual = ft_strcmp(SIMPLE_STR, EMPTY_STR);
	Assert_true(actual > 0, "simple / empty strings");

	actual = ft_strcmp(LONG_STR, EMPTY_STR);
	Assert_true(actual > 0, "long / empty strings");

	actual = ft_strcmp(EMPTY_STR, LONG_STR);
	Assert_true(actual < 0, "empty / long strings");

	// Second string not equal
	actual = ft_strcmp(SIMPLE_STR, EMPTY_STR);
	Assert_true(actual > 0, "simple / empty strings");

	actual = ft_strcmp(SIMPLE_STR, LONG_STR);
	Assert_true(actual < 0, "simple / long");

	actual = ft_strcmp(EMPTY_STR, SIMPLE_STR);
	Assert_true(actual < 0, "empty / simple strings");

	actual = ft_strcmp(LONG_STR, SIMPLE_STR);
	Assert_true(actual > 0, "long / simple strings");
}

void	Test_strcpy(void)
{
	char actual[LONG_STR_SIZE + 1];

	Test_Header("Strcpy");

	// Check null-byte
	ft_strcpy(actual, EMPTY_STR);
	Assert_true(actual[EMPTY_STR_SIZE] == '\0', "null-byte empty string");

	ft_strcpy(actual, SIMPLE_STR);
	Assert_true(actual[SIMPLE_STR_SIZE] == '\0', "null-byte simple string");

	ft_strcpy(actual, LONG_STR);
	Assert_true(actual[LONG_STR_SIZE] == '\0', "null-byte long string");

	// Check copy
	memset(actual, 0, LONG_STR_SIZE);
	ft_strcpy(actual, EMPTY_STR);
	Assert_str(EMPTY_STR, actual, "empty string copy");

	memset(actual, 0, LONG_STR_SIZE);
	ft_strcpy(actual, SIMPLE_STR);
	Assert_str(SIMPLE_STR, actual, "simple string copy");

	memset(actual, 0, LONG_STR_SIZE);
	ft_strcpy(actual, LONG_STR);
	Assert_str(LONG_STR, actual, "long string copy");
}

void	Test_strdup(void)
{
	char *actual;

	Test_Header("Strdup");

	// Check null-byte and duplicate
	actual = ft_strdup(EMPTY_STR);
	if (actual == NULL)
		return ;
	Assert_str(EMPTY_STR, actual, "empty string duplicate");
	free(actual);

	actual = ft_strdup(SIMPLE_STR);
	if (actual == NULL)
		return ;
	Assert_true(actual[SIMPLE_STR_SIZE] == '\0', "null-byte simple string");
	Assert_str(SIMPLE_STR, actual, "simple string duplicate");
	free(actual);

	actual = ft_strdup(LONG_STR);
	if (actual == NULL)
		return ;
	Assert_true(actual[LONG_STR_SIZE] == '\0', "null-byte long string");
	Assert_str(LONG_STR, actual, "long string duplicate");
	free(actual);
}

void	Test_read(void)
{
	char	expect_buff[BUFF_SIZE + 1];
	char	actual_buff[BUFF_SIZE + 1];
	int		actual_ret;
	int		expect_ret;
	t_pair	fd;

	Test_Header("Read");

	fd.first = open(TEST_FILE1, O_RDONLY);
	if (fd.first < 0)
	{
		puts(strerror(errno));
		return ;
	}
	fd.second = open(TEST_FILE2, O_RDONLY);
	if (fd.second < 0)
	{
		close(fd.first);
		puts(strerror(errno));
		return ;
	}
	expect_ret = read(fd.first, expect_buff, BUFF_SIZE);
	actual_ret = ft_read(fd.second, actual_buff, BUFF_SIZE);
	expect_buff[expect_ret] = '\0';
	actual_buff[actual_ret] = '\0';
	Assert_str(expect_buff, actual_buff, "Read from file");

	// Read from stdin
	write(STDIN_FILENO, "read> ", 6);
	expect_ret = read(STDIN_FILENO, expect_buff, BUFF_SIZE);
	write(STDIN_FILENO, "ft_read> ", 9);
	actual_ret = ft_read(STDIN_FILENO, actual_buff, BUFF_SIZE);
	expect_buff[expect_ret] = '\0';
	actual_buff[actual_ret] = '\0';
	Assert_str(expect_buff, actual_buff, "Read from stdin");
	
	close(fd.first);
	close(fd.second);
	// Read from closed fd
	actual_ret = ft_read(fd.second, actual_buff, BUFF_SIZE);
	Assert_true(actual_ret < 0, "Read from closed fd")
	Assert_int(errno, EBADF, "Read from closed fd");

	// Read from bad fd
	errno = 0;
	actual_ret = ft_read(-10, actual_buff, BUFF_SIZE);
	Assert_true(actual_ret < 0, "Read from bad fd");
	Assert_int(errno, EBADF, "Read from bad fd");
}

int	main(void)
{
	Test_write();
	Test_strlen();
	Test_strcmp();
	Test_strcpy();
	Test_strdup();
	Test_read();
	return (0);
}
