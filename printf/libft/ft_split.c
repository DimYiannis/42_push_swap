/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:31:12 by yiannis           #+#    #+#             */
/*   Updated: 2025/10/16 09:42:04 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	word_length(char *s, char c)
{
	int	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static void	*free_up(char **arr, int n)
{
	while (n-- >= 0)
		free(arr[n]);
	free(arr);
	return (NULL);
}

static char	**eachword(char *s, char c, char **result)
{
	int	j;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = malloc(word_length(s, c) + 1);
			if (!result[i])
				return (free_up(result, i - 1));
			j = 0;
			while (*s && *s != c)
				result[i][j++] = *s++;
			result[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	eachword((char *)s, c, result);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "hello-----there";
// 	char str2[] = "when i wake up in a morning love";
// 	char **arr1;
// 	char **arr2;
// 	int i;

// 	i = 0;
// 	arr1 = ft_split(str1, '-');
// 	while (arr1[i])
// 	{
// 		printf("%s\n", arr1[i]);
// 		i++;
// 	}
// 	i = 0;
// 	printf("\n");
// 	arr2 = ft_split(str2, ' ');
// 	while (arr2[i])
// 	{
// 		printf("%s\n", arr2[i]);
// 		i++;
// 	}
// 	return (0);
// }