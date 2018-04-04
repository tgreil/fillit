/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:35:24 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/04 17:28:35 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_usage(void)
{
	ft_putstr("usage : ./fillit source_file\n");
	return (EXIT_SUCCESS);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*unc_s1;
	unsigned char	*unc_s2;
	size_t			i;

	i = 0;
	unc_s1 = (unsigned char *)s1;
	unc_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (unc_s1[i] != unc_s2[i])
			return (unc_s1[i] - unc_s2[i]);
		i++;
	}
	return (0);
}

int			ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (EXIT_SUCCESS);
}

int			ft_putchar(int c)
{
	return (write(1, &c, 1));
}
