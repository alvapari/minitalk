/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:40:41 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 18:55:03 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	nstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstr == NULL)
		return (NULL);
	while (s1[count])
		nstr[count2++] = s1[count++];
	count = 0;
	while (s2[count] != '\0')
		nstr[count2++] = s2[count++];
	nstr[count2++] = '\0';
	return (nstr);
}

/*
int	main(void)
{
	char    *s1 = "ABCD'\0EFGH";
	char    *s2 = "ey, QUÉ, ey";
	printf ("%s", ft_strjoin (s1, s2));
    printf ("\n%c", s1[6]);
}*/