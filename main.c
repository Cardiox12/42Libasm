/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:32:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/25 00:29:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

extern ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dst, const char *src);
extern ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
extern char		*ft_strdup(const char *s1);


#ifdef MAIN

int	main(void)
{
	int diff;

	if ((diff = ft_strcmp("bon", "")))
		printf("%i\n", diff);
	return (0);
}

#endif

#ifdef UNITTEST

# include <criterion/criterion.h>

# define STRING_FMT "Expected %s but got %s\n"
# define INTEGER_FMT "Expected %i but got %i\n"
# define WINT_FMT "Expected %zu but got %zu\n"
# define PTR_FMT "Expected %p but got %p\n"
# define TEST_STRING "Hello World!\n"
# define TEST_STRING_SIZE 13
# define TEST_EMPTY_STRING ""


Test(simple, write_test)
{
	ssize_t actual;
	ssize_t expect;

	actual = ft_write(1, TEST_STRING, strlen(TEST_STRING));
	expect = write(1, TEST_STRING, strlen(TEST_STRING));
	cr_assert_eq(actual, expect, WINT_FMT, expect, actual);
}

Test(simple, strlen_test)
{
	size_t actual;
	size_t expect;

	actual = ft_strlen(TEST_STRING);
	expect = strlen(TEST_STRING);
	cr_assert(actual == expect, WINT_FMT, expect, actual);
	actual = ft_strlen(TEST_EMPTY_STRING);
	expect = strlen(TEST_EMPTY_STRING);
	cr_assert(actual == expect, WINT_FMT, expect, actual);
}

Test(simple, strcmp_test)
{
	int actual;
	int expect;

	actual = ft_strcmp(TEST_EMPTY_STRING, TEST_EMPTY_STRING);
	expect = strcmp(TEST_EMPTY_STRING, TEST_EMPTY_STRING);
	cr_expect(actual == expect, INTEGER_FMT, expect, actual);
	actual = ft_strcmp(TEST_STRING, TEST_STRING);
	expect = strcmp(TEST_STRING, TEST_STRING);
	cr_expect(actual == expect, INTEGER_FMT, expect, actual);
	// Same size, different characters
	actual = ft_strcmp("toto", "totu");
	expect = strcmp("toto", "totu");
	cr_expect(actual == expect, INTEGER_FMT, expect, actual);
	// Different size, different characters 
	actual = ft_strcmp("toto", "totou");
	expect = strcmp("toto", "totou");
	cr_expect(actual == expect, INTEGER_FMT, expect, actual);
	// Different size, different characters
	actual = ft_strcmp("totou", "toto");
	expect = strcmp("totou", "toto");
	cr_expect(actual == expect, INTEGER_FMT, expect, actual);
	// Empty string, different characters
	actual = ft_strcmp(TEST_EMPTY_STRING, "toto");
	expect = strcmp(TEST_EMPTY_STRING, "toto");
	cr_expect(actual == expect, INTEGER_FMT, expect, actual);
	// Different characters, empty string
	actual = ft_strcmp("toto", TEST_EMPTY_STRING);
	expect = strcmp("toto", TEST_EMPTY_STRING);
	cr_expect(actual == expect, INTEGER_FMT, expect, actual);
}

Test(simple, strcpy_test)
{
	// Copy empty string
	// Copy non empty string
	// Test content
	// Test pointer
	// Test null byte
	char actual[ 20 ];
	char *ptr;

	ptr = ft_strcpy(actual, TEST_EMPTY_STRING);
	cr_expect_str_empty(actual, "Expected empty string but got %s\n", actual);
	cr_expect(ptr == &actual[0], PTR_FMT, actual, ptr);

	ptr = ft_strcpy(actual, TEST_STRING);
	cr_expect_str_eq(actual, TEST_STRING, STRING_FMT, TEST_STRING, actual);
	cr_expect(ptr == &actual[0], PTR_FMT, actual, ptr);
	cr_expect(actual[TEST_STRING_SIZE] == '\0', "Expected null byte but got %c", actual[TEST_STRING_SIZE]);
}

Test(simple, strdup_test)
{
	char *actual;

	actual = ft_strdup(TEST_EMPTY_STRING);
	if (actual)
	{
		cr_expect_str_empty(actual, "Expected empty string but got %s\n", actual);
		free(actual);
	}

	actual = ft_strdup(TEST_STRING);
	if (actual)
	{
		cr_expect_str_eq(actual, TEST_STRING, STRING_FMT, TEST_STRING, actual);
		free(actual);
	}
}

#endif