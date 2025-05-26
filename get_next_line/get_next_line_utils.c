/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:07:09 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/12 22:08:40 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
  size_t	i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

char	*ft_strchr(const char *s, int c)
{
  t_uint8_t	uc;

  uc = (t_uint8_t)c;
  if (!s)
    return (NULL);
  while (*s)
  {
    if (*s == uc)
      return ((char *)s);
    s++;
  }
  if (uc == '\0')
    return ((char *)s);
  return (NULL);
}

char	*ft_strdup(const char *s)
{
  int		i;
  int		len;
  char	*dst;

  if (!s)
    return (NULL);
  i = 0;
  len = ft_strlen(s);
  dst = (char *)malloc((len + 1) * sizeof(char));
  if (dst == NULL)
    return (NULL);
  while (s[i])
  {
    dst[i] = s[i];
    i++;
  }
  dst[i] = '\0';
  return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
  size_t	i;
  size_t	src_len;

  src_len = ft_strlen(src);
  if (size == 0)
    return (src_len);
  i = 0;
  while (src[i] != '\0' && i < size - 1)
  {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return (src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
  size_t	cpy_len;
  char	*dst;

  if (!s)
    return (NULL);
  cpy_len = ft_strlen(s);
  if (start >= cpy_len)
    return (ft_strdup(""));
  if (cpy_len - start < len)
    cpy_len -= start;
  else
    cpy_len = len;
  dst = (char *)malloc((cpy_len + 1) * sizeof(char));
  if (!dst)
    return (NULL);
  ft_strlcpy(dst, s + start, cpy_len + 1);
  return (dst);
}

static size_t	total_len(char const *s1, char const *s2)
{
  size_t	total_len;

  total_len = ft_strlen(s1) + ft_strlen(s2);
  return (total_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
  size_t	i;
  size_t	j;
  char	*dst;

  if (!s1 || !s2)
    return (NULL);
  dst = (char *)malloc((total_len(s1, s2) + 1) * sizeof(char));
  if (!dst)
    return (NULL);
  i = 0;
  while (s1[i])
  {
    dst[i] = s1[i];
    i++;
  }
  j = 0;
  while (s2[j])
  {
    dst[i + j] = s2[j];
    j++;
  }
  dst[i + j] = '\0';
  return (dst);
}
