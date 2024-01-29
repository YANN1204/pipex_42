/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:26:00 by yrio              #+#    #+#             */
/*   Updated: 2024/01/29 17:40:17 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	part;

	part = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			part++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (part);
}

char	**ft_free(char **char_tab, int nb_words)
{
	while (nb_words >= 0)
		free(char_tab[nb_words--]);
	free(char_tab);
	return (NULL);
}

static char	*ft_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**char_tab;
	int		i;
	int		nb_words;

	nb_words = count_words(s, c);
	char_tab = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (char_tab == NULL)
		return (NULL);
	i = 0;
	while (*s && i < nb_words)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			char_tab[i] = ft_word(s, c);
			if (char_tab[i] == NULL)
				return (ft_free(char_tab, nb_words));
			i++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	char_tab[i] = 0;
	return (char_tab);
}

/*
int		main(void)
{
	//char *splitme = strdup("/");
	char **tab;
	
	tab = ft_split("", ' ');
	printf("tab : %s\n", tab[3]);
	return (0);
}
*/

/*
int		main(void)
{
	char 	*str = "111111111111hello1test1bonjour111";
	char 	c = '1';
	char 	**char_tab;

	char_tab = ft_split(str, c);
	printf("%s\n", char_tab[0]);
	printf("%s\n", char_tab[1]);
	printf("%s\n", char_tab[2]);
	printf("%s\n", char_tab[3]);
	return (0);
}
*/