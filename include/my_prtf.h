/*
** my_prtf.h for lib in /home/Realague/Delivery/B_MUL/raytracer2/include/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Sun May 28 18:22:39 2017 Julien Delane
** Last update Sun May 28 22:19:10 2017 Benjamin
*/

#ifndef MY_PRTF_H_
# define MY_PRTF_H_
# define ERROR_MSG "error"

# include <stdarg.h>

char    *float_str(float nbr);
int	my_printf(char *str, ...);
void	my_putchar_pf(char c, int *count);
void	my_putchar_u_pf(unsigned char c, int *count);
int	my_strlen_pf(char *str);
void    my_putstr_pf(char *str, int *count);
void	my_putstr_oct_pf(char *str, int *count);
void	my_put_nbr_pf(int nb, int *count);
void    my_put_nbr_u_pf(unsigned int nb, int *count);
void    my_put_nbr_long_pf(long nb, int *count);
void    my_putchar2_pf(char c);
void    my_putstr2_pf(char *str);
int	my_po_pf(int nb, int i);
void	my_putnbr_base_pf(unsigned int nbr, char *base, int *count);
void    my_base_long_pf(unsigned long long int nbr, char *base, int *count);
void    my_pointer_adress_pf(void *ptr, int *count);
void    put_type_pf(va_list ap, char *str, int *i);
void    put_flag_pf(char *str, int *i);
char    *tab_flag_pf();
void    tab_fonc_pf(int i, va_list ap, int *count);
void    check_mallc_pf(char *str);
int     check_flag_pf(char *str, int i);
int     check_type_pf(char *str, int i);
int     check_int_pf(char c);
int     check_int_flag_pf(char c);
void	the_c_pf(va_list ap, int *count);
void    the_s_pf(va_list ap, int *count);
void	the_i_d_pf(va_list ap, int *count);
void	the_x_pf(va_list ap, int *count);
void	the_big_x_pf(va_list ap, int *count);
void	the_o_pf(va_list ap, int *count);
void    the_u_pf(va_list ap, int *count);
void	the_b_pf(va_list ap, int *count);
void    the_s_oct_pf(va_list ap, int *count);
void	the_p_pf(va_list ap, int *count);

#endif /* !MY_PRTF_H_ */
