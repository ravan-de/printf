/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/30 14:35:14 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/30 14:35:16 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "printf.h"

void ft_print_rev(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    while (str[i] > 0)
    {
        i--;
        ft_putchar(str[i]);
    }
}

void ft_convbase(unsigned int nb, unsigned int base, char **retstr, int index)
{
    if (nb >= base)
    {
        ft_convbase(nb / base, base, retstr, index + 1);
        nb %= base;
    }
    if (nb > 9)
        (*retstr)[index] = nb + 55;
    else
        (*retstr)[index] = nb + 48;
}

/*void    ft_processflags(char *str, va_list arglst, int field_width, char *flags)
{
    char    *printstr;
    
    printstr = ft_strnew(1000)
    if (ft_strchr(flags, 'd') != NULL || ft_strchr(flags, 'i') != NULL || ft_strchr(flags, 'u') != 0)
        ft_proc_int(arglst, flags)
    if (flags[0] == '%')
        ft_putchar('%');
    else if (*str == 'c')
        ft_putchar(va_arg(arglst, int));
    else if (*str == 's')
        ft_strcpy(printstr, va_arg(arglst, char *));
    else if (*str == 'p')
        ft_convbase(va_arg(arglst, unsigned), 16, &printstr, 0);
    else if (*str == 'd' || *str == 'i')
        printstr = ft_itoa(va_arg(arglst, int)));
    else if (*str == 'o')
        ft_convbase(va_arg(arglst, int), 8, &retstr, 0);
    else if (*str == 'u')
        printstr = ft_itoa(va_arg(arglst, int));
    else if (*str == 'x')
        ft_convbase(va_arg(arglst, int), 16, &retstr, 0);
    else if (*str == 'X')
        ft_convbase(va_arg(arglst, int), 16, &retstr, 0);
}*/

/*void ft_fieldwidth(char *str)
{
    size_t len;

    len = 0;
    len = field_width - ft_strlen(str);
    while (len > 0)
    {
        if (ft_strchr(flags, '0') != NULL)
            ft_putchar('0');
        else
            ft_putchar(' ');
        len--;
    }
}*/

int ft_getmods(char *str)
{
    if (*str == '#')
        return (1);
    if (*str == '-')
        return (2);
    if (*str == '+')
        return (4);
    if (*str == ' ')
        return (8);
    if (*str == '0')
        return (16);
    return (0);
}

int ft_get_typeflags(char *str)
{
    if (*str == 'c' || *str == 'C')
        return (0);
    if (*str == 's' || *str == 'S')
        return (1);
    if (*str == 'p' || *str == 'P')
        return (2);
    if (*str == 'd' || *str == 'D')
        return (3);
    if (*str == 'i' || *str == 'I')
        return (4);
    if (*str == 'o' || *str == 'O')
        return (5);
    if (*str == 'u' || *str == 'U')
        return (6);
    if (*str == 'x')
        return (7);
    if (*str == 'X')
        return (8);
    return (-1);
}

int ft_get_modflags(char *str, va_list arglst)
{
    size_t  i;
    int     mods;
    int     field_width;
    int     precision;

    i = 0;
    mods = 0;
    field_width = 0;
    (void)arglst;
    while (ft_getmods(&str[i]) != 0)
    {
        mods |= ft_getmods(&str[i]);
        i++;
    }
    if (str[i] > '0' && str[i] <= '9')
        field_width = ft_atoi(&str[i]);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == '.')
        precision = ft_atoi(&str[i]);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    ft_get_typeflags(&str[i]);
    //ft_process_flags(int mods, int field_width, int precision, /*return from get_typeflags */);
    return (i);
}

void ft_printf(char *str, ...)
{
    va_list arglst;
    int     stri;

    stri = 0;
    va_start(arglst, str);
    while (str[stri] != '\0')
    {
        if (str[stri] == '%')
            stri += ft_get_modflags(&str[stri + 1], arglst);
        else
        {
            ft_putchar(str[stri]);
            stri++;
        }
    }
    va_end(arglst);
}

int main(void)
{
    short   h;
    h = 10;
    int *ptr;
    int **ptrptr;
    int a;

    a = 6000;
    ptr = NULL;
    ptrptr = NULL;
    ptr = &a;
    ptrptr = &ptr;
    ft_printf("Zaanse mayo %d\n", 10);
    //printf("Zaanse mayo %x\n", 200);
    return (1);
}