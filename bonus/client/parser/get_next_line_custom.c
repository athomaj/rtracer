/*
** get_next_line_custom.c for lem-in in /home/archer_j/rendu/lemin_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Mon Apr 14 08:54:19 2014 archer
** Last update Fri May 30 11:34:33 2014 archer
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

void		sans_nom(char *str, int i)
{
  int		a;

  a = strlen(str) + 1;
  while ((str[--a] == ' ' || str[a] == '\t') && a > 0);
  str[a] = 0;
  a = i - 1;
  while (str[++a] != '\0' && str[a] != '#');
  ++a;
  while (str[--a] == ' ' || str[a] == '\t');
  str[a] = 0;
}

char		*get_next_line_custom(FILE *file)
{
  char		*str;
  char		*str2;
  int		i;
  int		a;
  size_t	o;

  str = NULL;
  if ((getline(&str, &o, file)) == -1)
    return (NULL);
  if (strlen(str) > 0 && str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = 0;
  i = -1;
  while (str[++i] == ' ' || str[i] == '\t');
  sans_nom(str, i);
  if ((str2 = malloc(strlen(str) - i + 1)) == NULL)
    return (NULL);
  a = -1;
  while (str[i] != '\0')
    str2[++a] = str[i++];
  str2[++a] = 0;
  free(str);
  return (str2);
}
