/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jona-pin <jona-pin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:20:47 by jona-pin          #+#    #+#             */
/*   Updated: 2023/08/29 18:56:24 by jona-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_map(char **map, int rows)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < rows)
		{
			if (map[i][j] >= '0' && map [i][j] <= '9')
			{	
				c = map [i][j] + '0';
				ft_putchar(c);
			}
			else
			{
				c = map [i][j];
				ft_putchar(c);
			}
		j++;
		}
		i++;
		ft_putchar('\n');
	}
}