/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ego <jose-ego@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:34:04 by jose-ego          #+#    #+#             */
/*   Updated: 2023/08/30 14:19:50 by jose-ego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_tam_filetest(char *file_name)
{
	int		tam;
	char	matrix;
	FILE	*filetest;

	tam = 0;
	filetest = open(file_name, "r");
	while (read(filetest, &matrix, 1))
	{
		tam++;
	}
	close(filetest);
	return (tam);
}

int	ft_rows_map(char *file_name)
{
	int		cont;
	char	*matrix;
	int		n_rows;
	FILE	*filetest;

	cont = 0;
	n_rows = 0;
	filetest = open(file_name, "r");
	matrix = (char *) malloc(40 * sizeof(char));
	if (matrix == NULL)
		return (0);
	while (read(filetest, &matrix[cont], 1))
	{
		if (matrix[cont] > 58 || matrix[cont] < 47)
			break ;
		n_rows = n_rows * 10 + (matrix[cont] - 48);
	}
	free(matrix);
	close(filetest);
	return (n_rows);
}

void	ft_saltar_rows(FILE *filetest)
{
	int		cont;
	char	*matrix;

	cont = 0;
	matrix = malloc(4096 * sizeof(char));
	if (matrix == NULL)
		return (NULL);
	while (read(filetest, &matrix[cont], 1))
	{
		if (matrix[cont] == '\n')
			break ;
		cont++;
	}
}

int	ft_colum_map(char *file_name)
{
	int		tam_filetest;
	FILE	*filetest;
	char	*rows;
	char	*matrix;
	int		n_colum;

	tam_filetest = ft_tam_filetest(file_name);
	filetest = fopen(file_name, "r");
	ft_saltar_rows(filetest);
	matrix = (char *) malloc(tam_filetest * sizeof(char));
	if (matrix == NULL)
		return (0);
	n_colum = 0;
	while (read(filetest, &matrix[n_colum], 1))
	{
		if (matrix[n_colum] == '\n')
			break ;
		n_colum++;
	}
	free(matrix);
	close(filetest);
	return (n_colum + 1);
}

char	**ft_read_file(char *file_name)
{
	FILE	*filetest;
	int		rows;
	int		colum;
	char	**matrix;
	int		cont;

	filetest = fopen(file_name, "r");
	if (filetest == NULL)
		return (NULL);
	colum = ft_colum_map(file_name);
	rows = ft_rows_map(file_name);
	ft_saltar_rows(filetest);
	matrix = (char *) malloc(rows * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	cont = 0;
	while (cont < rows)
	{
		matrix[cont] = malloc(colum * sizeof(char));
		if (matrix[cont] == NULL)
			return (NULL);
		cont++;
	}	
	cont = 0;
	while (cont < rows)
	{
		if ((read(filetest, matrix[cont], colum) == -1))
			return (NULL);
		matrix[cont][colum -1] = '\0';
		cont++;
	}
	close(filetest);
	return (matrix);
}
