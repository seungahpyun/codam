/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strdup.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: spyun <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/09 10:34:53 by spyun          #+#    #+#                */
/*   Updated: 2024/10/09 10:34:54 by spyun          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s) + 1;
	str = (char *)ft_calloc(i, sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	return (str);
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
// 	const char *s = "Hello, World!";
// 	char *copy = ft_strdup(s);

// 	if (copy)
// 	{
// 		printf("Original: %s\n", s);
// 		printf("Copy: %s\n", copy);
// 		free(copy);
// 	}
// 	else
// 		printf("Memory allocation failed\n");
// 	return 0;
// }