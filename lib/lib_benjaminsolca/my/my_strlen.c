/*
** my_strlen.c for my_lib in /home/benjamin/Dropbox/func/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Sun Apr  2 20:38:52 2017 Benjamin
** Last update Wed May 24 11:12:51 2017 Benjamin
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (*str != '\0')
    {
      i = i + 1;
      str = str + 1;
    }
  return (i);
}
