/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rostring.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 16:33:29 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/18 16:57:17 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		ft_count_words(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[i] != 32 && s[i] != 9 && s[i] != 11)
		j++;
	while (s[i])
	{
		if (s[i] == 32 || s[i] == 9 || s[i] == 11)
		{
			i++;
			if (s[i] && s[i] != 32 && s[i] != 9 && s[i] != 11)
				j++;
			i--;
		}
		i++;
	}
	return (j);
}

int		ft_count_letters(char *s, int pos)
{
	int i;

	i = 0;
	while (s[pos] && s[pos] != 32 && s[pos] != 9 && s[pos] != 11)
	{
		pos++;
		i++;
	}
	return (i);
}

char	*ft_strsub(char *s, int pos, int len)
{
	int i;
	char *ret;
	
	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i != len)
	{
		ret[i] = s[pos];
		i++;
		pos++;
	}
	ret[i] = '\0';
	return (ret);
}

void	rostring(char *s)
{
	int i;
	int j;
	int k;
	char **ret;

	i = ft_count_words(s);
	j = 0;
	k = 0;
	ret = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && s[i] != 9 && s[i] != 11)
		{
			j = ft_count_letters(s, i);
			ret[k] = ft_strsub(s, i, j);
			k++;
			i += j - 1;
		}
		i++;
	}
	ret[k] = NULL;
	k = 1;
	while (ret[k])
	{
		ft_putstr(ret[k]);
		ft_putchar(' ');
		k++;
	}
	ft_putstr(ret[0]);
}

int		main(int ac, char **av)
{
	if (ac >= 2)
		rostring(av[1]);
	write (1, "\n", 1);
	return (0);
}
