/*
** error_function.c for raytracer in /home/archer_j/rendu/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Wed May  7 11:41:00 2014 archer
** Last update Wed May  7 12:02:56 2014 archer
*/

#include	<stdio.h>

int		error_function(char *err, int l, int ret)
{
  if (l == -1)
    fprintf(stderr, "%s\n", err);
  else
    fprintf(stderr, "%s line %d\n", err, l);
  return (ret);
}
