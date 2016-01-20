/*
** lexer.c for raytracer in /home/archer_j/rendu/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Wed May  7 18:05:40 2014 archer
** Last update Sun Jun  8 15:04:46 2014 borel_d
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"raytracer.h"
#include	"parser.h"

int		add_elem_to_list(t_list **list, char *str, int nb, int type)
{
  t_list	*elem;
  t_list	*tmp;

  if ((elem = malloc(sizeof(t_list))) == NULL ||
      (elem->lexeme = strndup(str, nb)) == NULL)
    return (-1);
  elem->type = type;
  tmp = *list;
  elem->next = NULL;
  if (tmp == NULL)
    {
      elem->prev = NULL;
      *list = elem;
    }
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (0);
}

int		check_type(char *seie, char c, int a, t_list *tmp)
{
  int		i;

  i = -1;
  while (++i < NB_LEX)
    if (seie[i] == c && (i == INHIB || tmp == NULL || tmp->type != INHIB ||
			 tmp->prev == NULL || tmp->prev->type == ELEM))
      return (i < 4 ? i : i - 1);
  if ((c == ' ' ||  c == '\t') && (tmp == NULL || tmp->type != INHIB ||
				   tmp->prev == NULL ||
				   tmp->prev->type == ELEM))
    return (-1);
  if (tmp != NULL && (tmp->type == START || tmp->type == END))
    return (TITLE);
  return (a == 0 ? VALUE : ELEM);
}

int		separe_line(t_list **list, char *str, int i, int *a)
{
  t_list	*tmp;
  char		*seie;
  int		n;
  int		l;

  seie = "<=\"/>";
  tmp = *list;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  n = check_type(seie, str[i], *a, tmp);
  l = i;
  while (check_type(seie, str[++l], *a, tmp) == n &&
	 n != INHIB && str[l] != 0);
  if (n == ELEM && (tmp != NULL && tmp->type == VALUE))
    n = VALUE;
  if (add_elem_to_list(list, &str[i], (l - i), n) == -1)
    {
      fprintf(stderr, "Malloc failed\n");
      return (-1);
    }
  if ((n == VALUE || n == ELEM) && (tmp == NULL || tmp->type != VALUE))
    *a = (*a + 1) % 2;
  return (l - 1);
}

int		lexer(t_list **list, char *str)
{
  int		i;
  int		a;

  i = -1;
  a = 0;
  if (str[0] == 0)
    return (-2);
  while (str[++i] != 0)
    {
      while (str[i] == ' ' || str[i] == '\t')
	i = i + 1;
      if (str[i] == 0)
	return (0);
      if ((i = separe_line(list, str, i, &a)) == -1)
	return (-1);
    }
  return (0);
}
