/*
** is_num.c for is_num in /home/benjamin/Dropbox/func/is_it/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Sun Apr  2 18:48:46 2017 Benjamin
** Last update Thu May  4 10:04:36 2017 Benjamin
*/

int	is_num(char c)
{
  return ((c >= '0' && c <= '9') || c == ',' || c == '.');
}
