/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:11:55 by alvapari          #+#    #+#             */
/*   Updated: 2024/02/18 20:17:07 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nword(const char *s, char c)
{
	size_t	count;
	size_t	del_count;

	count = 0;
	del_count = 0;
	while (s[count] != '\0')
	{
		while (s[count] == c)
			count++;
		while (s[count] != c && (s[count] != '\0'))
			count++;
		while (s[count] == c && (s[count] != '\0'))
			count++;
		del_count++;
	}
	return (del_count);
}

char	**ft_free(char **sentence)
{
	int	count;

	count = 0;
	while (sentence[count])
	{
		free(sentence[count]);
		count++;
	}
	free(sentence);
	return (NULL);
}

char	**ft_aux_split(char **sentence, const char *s, char c, int count)
{
	int	cnt_pos;

	cnt_pos = 0;
	while (s[count])
	{
		while (s[count] != c && (s[count] != '\0'))
			count++;
		sentence[cnt_pos] = ft_substr(s, 0, count);
		if (!sentence[cnt_pos])
		{
			ft_free(sentence);
			return (NULL);
		}
		s = s + count;
		cnt_pos++;
		count = 0;
		while (s[count] == c && (s[count] != '\0'))
			count++;
		s = s + count;
		count = 0;
	}
	sentence[cnt_pos] = NULL;
	return (sentence);
}

char	**ft_split(char const *s, char c)
{
	char	**sentence;
	int		count;

	count = 0;
	sentence = malloc((sizeof(char *) * ((ft_nword(s, c)) + 1)));
	if (!sentence || !s)
		return (NULL);
	while (s[count] == c && s[count] != '\0')
		count++;
	s = s + count;
	count = 0;
	return (ft_aux_split(sentence, s, c, count));
}

/*
int	main(void)
{
	char	*s;
	char	**splitted;
	int		i;

	s = "                  olol";
	splitted = ft_split(s, ' ');
	i = 0;
	while (splitted[i])
	{
		printf("%s\n", splitted[i]);
		i++;
	}
	free(splitted);
	return (0);
}*/
