/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:32:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/06 16:48:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

# define STRING "tut"
# define STRING2 "toto"

extern ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dst, const char *src);

int		main()
{
	char dst_1[10];
	char dst_2[10];

	ft_write(1, STRING, 4);
	ft_write(1, "\n", 1);
	printf("strlen(\"%s\") : %zu\n", STRING, strlen(STRING));
	printf("ft_strlen(\"%s\") : %zu\n", STRING, ft_strlen(STRING));
	printf("strcmp(\"%s\", \"%s\") : %i\n", STRING, STRING2, strcmp(STRING, STRING2));
	ft_strcmp(STRING, STRING2);
	printf("ft_strcmp(\"%s\", \"%s\") : %i\n", STRING, STRING2, ft_strcmp(STRING, STRING2));
	strcpy(dst_1, STRING);
	ft_strcpy(dst_2, STRING);
	printf("strcpy : %s\n", dst_1);
	printf("ft_strcpy : %s\n", dst_2);
	return (0);
}