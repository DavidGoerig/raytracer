/*
** is_alphanum.c for is_alphanum in /home/benjamin/Dropbox/func/is_it/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Sun Apr  2 18:51:58 2017 Benjamin
** Last update Thu May 25 18:03:45 2017 Benjamin
*/

#include "bs.h"

int	is_alphanum(char c)
{
  return (c == '-' || is_alpha(c) || is_num(c) || c == '_');
}
