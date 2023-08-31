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

int	ft_tam_archivo(char *file_name)
{
	int		tam;
	char	almacen;
	FILE	*archivo;

	tam = 0;
	archivo = open(file_name, "r");
	while (read(archivo, &almacen, 1))
	{
		tam++;
	}
	close(archivo);
	return (tam);
}

int	ft_lineas_mapa(char *file_name)
{
	int		cont;
	char	*almacen;
	int		n_lineas;
	FILE	*archivo;

	cont = 0;
	n_linea = 0;
	archivo = open(file_name, "r");
	almacen = (char *) malloc(40 * sizeof(char));
	if (almacen == NULL)
		return (0);
	while (read(archivo, &almacen[cont], 1))
	{
		if (almacen[cont] > 58 || almacen[cont] < 47)
			break ;
		n_lineas = n_lineas * 10 + (almacen[cont] - 48);
	}
	free(almacen);
	close(archivo);
	return (n_lineas);
}

void	ft_saltar_linea(FILE *archivo)
{
	int		cont;
	char	*almacen;

	cont = 0;
	almacen = malloc(4096 * sizeof(char));
	if (almacen == NULL)
		return (NULL);
	while (read(archivo, &almacen[cont], 1))
	{
		if (almacen[cont] == '\n')
			break ;
		cont++;
	}
}

int	ft_columnas_mapa(char *file_name)
{
	int		tam_archivo;
	FILE	*archivo;
	char	*linea;
	char	*almacen;
	int		n_columnas;

	tam_archivo = ft_tam_archivo(file_name);
	archivo = fopen(file_name, "r");
	ft_saltar_linea(archivo);
	almacen = (char *) malloc(tam_archivo * sizeof(char));
	if (almacen == NULL)
		return (0);
	n_columnas = 0;
	while (read(archivo, &almacen[n_columnas], 1))
	{
		if (almacen[n_columnas] == '\n')
			break ;
		n_columnas++;
	}
	free(almacen);
	close(archivo);
	return (n_columnas + 1);
}

char	**ft_read_file(char *file_name)
{
	FILE	*archivo;
	int		lineas;
	int		columnas;
	char	**almacen;
	int		cont;

	archivo = fopen(file_name, "r");
	if (archivo == NULL)
		return (NULL);
	columnas = ft_columnas_mapa(file_name);
	lineas = ft_lineas_mapa(file_name);
	ft_saltar_linea(archivo);
	almacen = (char *) malloc(lineas * sizeof(char *));
	if (almacen == NULL)
		return (NULL);
	cont = 0;
	while (cont < lineas)
	{
		almacen[cont] = malloc(columnas * sizeof(char));
		if (almacen[cont] == NULL)
			return (NULL);
		cont++;
	}	
	cont = 0;
	while (cont < lineas)
	{
		if ((read(archivo, almacen[cont], columnas) == -1))
			return (NULL);
		almacen[cont][columnas -1] = '\0';
		cont++;
	}
	close(archivo);
	return (almacen);
}
