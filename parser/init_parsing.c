/*
** init_parsing.c for raytracer in /home/archer_j/rendu/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Wed May  7 11:19:14 2014 archer
** Last update Sun Jun  8 23:27:37 2014 archer
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"raytracer.h"
#include	"parser.h"

static char	*concat_files(char *file, char *tmp)
{
  char		*str;
  int		i;

  i = strlen(tmp);
  while (--i >= 0 && tmp[i] != '/');
  if ((str = malloc(strlen(file) + i + 2)) == NULL)
    return (NULL);
  strncpy(str, tmp, i + 1);
  strcat(str, file);
  return (str);
}

static int	add_file_to_list(t_file **files, char *file)
{
  t_file	*elem;
  t_file	*tmp;

  if ((elem = malloc(sizeof(t_file))) == NULL)
    return (error_function("Malloc failed\n", -1, -1));
  tmp = *files;
  elem->name = strdup(file);
  elem->next = *files;
  *files = elem;
  if (tmp == NULL)
    return (0);
  while (tmp->next != NULL)
    tmp = tmp->next;
  free(elem->name);
  if ((elem->name = concat_files(file, tmp->name)) == NULL)
    return (-1);
  tmp = *files;
  while (tmp != NULL)
    {
      if (tmp != *files && strcmp(tmp->name, (*files)->name) == 0)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

static int	start_parsing(t_all *infos, FILE *fd, char *file)
{
  t_list	*list;
  char		*str;
  int		line;
  int		err;

  line = 0;
  while ((str = get_next_line_custom(fd)) != NULL && ++line > 0)
    {
      err = 0;
      list = NULL;
      if ((err = lexer(&list, str)) == -1)
	{
	  printf("File: %s\n", file);
	  return (error_function(SYNTAX_ERROR, line, -1));
	}
      line = line + send_to_fct(infos, list, fd, &err);
      if (err == -1)
	{
	  printf("File: %s\n", file);
	  return (error_function(SYNTAX_ERROR, line, -1));
	}
      free_things(list, str);
    }
  return (0);
}

int		parsing(t_all *infos, char *file)
{
  FILE		*fd;
  int		err;

  if (add_file_to_list(&infos->files, file) == -1)
    {
      fprintf(stderr, "%s : file already opened\n", file);
      return (-1);
    }
  if ((fd = fopen(infos->files->name, "r")) == NULL)
    return (error_function(OPEN, -1, -1));
  err = start_parsing(infos, fd, infos->files->name);
  if (fclose(fd) == -1)
    return (error_function(CLOSE, -1, -1));
  return ((err == -1) ? err : 0);
}

int		init_parsing(t_all *infos, char **av)
{
  int		i;

  i = 0;
  while (av[++i] != 0)
    if (parsing(infos, av[i]) == -1)
      return (-1);
  return (0);
}
