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

#ifndef PRINTF_H
# define PRINTF_H

typedef enum    e_flags
{
                h,
                l,
                c,
                C = 2,
                s,
                S = 3,
                p,
                P = 4,
                d,
                D = 5,
                i,
                I = 6,
                o,
                O = 7,
                u,
                U = 9,
                x,
                X = 10,
                f
}               t_flags;

/*
number fetched from enum will be used in list of funtion pointers to select the right function.
This way my printf will be easily exstendable by adding a new flag to the end of the enum and a new funtion ptr to the end of the array.
 */

#endif

/*

if string is entered for %d or an int for %s: segfault


make variadic funct ptr and have every print function interpit the type 

ft_putstr(char *str)
ft_putnbr(int)


 */