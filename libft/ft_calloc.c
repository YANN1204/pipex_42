/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:45:41 by yrio              #+#    #+#             */
/*   Updated: 2023/11/15 16:23:30 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (size > 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	s = (void *)malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
/*
int 	main(void)
{
	unsigned long long int 	nmemb = SIZE_MAX;
	unsigned long long int 	size = 1;
	void 	*s;
	void 	*s2;

	s = ft_calloc(nmemb, size);
	s2 = calloc(nmemb, size);
	//printf("%lu", sizeof(s));
	//printf("%lu", sizeof(s2));
	if (s != NULL)
	{
		free(s);
		printf("bien malloc");
	} 
	else 
	{
		printf("mal malloc");
	} 
	if (s2 != NULL)
	{
		free(s2);
		printf("bien malloc");
	} 
	else 
	{
		printf("mal malloc");
	} 
	return (0);
}
*/