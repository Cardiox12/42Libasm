/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:32:33 by bbellavi          #+#    #+#             */
/*   Updated: 2020/07/04 21:00:44 by bbellavi         ###   ########.fr       */
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

int		main()
{
	ft_write(1, STRING, 4);
	ft_write(1, "\n", 1);
	printf("strlen(\"%s\") : %zu\n", STRING, strlen(STRING));
	printf("ft_strlen(\"%s\") : %zu\n", STRING, ft_strlen(STRING));
	printf("strcmp(\"%s\", \"%s\") : %i\n", STRING, STRING2, strcmp(STRING, STRING2));
	ft_strcmp(STRING, STRING2);
	printf("ft_strcmp(\"%s\", \"%s\") : %i\n", STRING, STRING2, ft_strcmp(STRING, STRING2));
	return (0);
}