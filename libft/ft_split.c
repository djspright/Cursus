/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:46:37 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 21:17:42 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!(*s == c))
		{
			count++;
			while (*s && !(*s == c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_len;
	size_t	i;
	char	**arr;

	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			arr[i] = ft_substr(s, 0, word_len);
			s += word_len;
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

// int	main(void)
// {
//   char	s[] = "Gaspard de la Nuit";
//   char	c;
//   char	**result;
//   size_t	i;
//
//   c = ' ';
//   i = 0;
//   result = ft_split(s, c);
//   while (result[i])
//   {
//     printf("%s\n", result[i]);
//     i++;
//   }
//   i = 0;
//   while(result[i])
//   {
//     free(result[i]);
//     i++;
//   }
//   free(result);
//   return (0);
// }
