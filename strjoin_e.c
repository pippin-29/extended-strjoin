/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:26:48 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/09 11:55:42 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlen(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*malloc_strlen_n(unsigned int c, va_list arg)
{
	unsigned int size;
	va_list arg_copy;

	va_copy(arg_copy, arg);
	size = 0; 
	while (c)
	{
		size += ft_strlen(va_arg(arg_copy, char *));
		c--;
	}
	va_end(arg_copy);
	return (malloc(sizeof(char) * (size + 1)));
}

char	*strjoin_e(unsigned int c, ...)
{
	va_list arg;
	char	*out;
	char	*tmp;
	int		i;
	int		j;

	va_start(arg, c);
	out = malloc_strlen_n(c, arg);
	j = 0;
	if (!out)
	{
		va_end(arg);
		return (0);
	}
	while (c)
	{
		i = 0;
		tmp = va_arg(arg, char *);
		while (tmp[i])
		{
			out[j] = tmp[i];
			j++;
			i++;
		}
		c--;
	}
	out[j] = '\0';
	va_end(arg);
	return (out);
}

int main (int argc, char **argv)
{
	if (argc == 6)
	{
		printf("%s\n", strjoin_e(5, argv[5], argv[4], argv[3], argv[2], argv[1]));
		printf("Parameters successfully joined into a single array, in reverse order.\n");
	}else{
		printf("Please Enter 5 Parameters\n");
	}
	return (0);
}


