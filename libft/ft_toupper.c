/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_toupper.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: spyun <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 09:09:15 by spyun          #+#    #+#                */
/*   Updated: 2024/10/08 09:09:17 by spyun          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= ('a' - 'A');
		return (c);
	}
	return (c);
}

// #include <stdio.h>

// int main(void)
// {
// 	char c = 'b';
// 	printf("%c\n", ft_toupper(c));
// 	char d = 'B';
// 	printf("%c\n", ft_toupper(d));
// 	char e = '1';
// 	printf("%c\n", ft_toupper(e));
// 	return 0;
// }
