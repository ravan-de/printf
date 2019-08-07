/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/30 14:35:14 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/30 14:35:16 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

print_int(va_list arglst)
{
    ft_putnbr(va_arg(arglst, int));
}

print_h(va_list arglst)
{
    ft_putnbr(va_arg(arglst, short));
}

print_hh(va_list arglst)
{
    ft_putnbr(va_arg(arglst, short short));
}

print_l(va_list arglst)
{
    ft_putnbr_l(va_arg(arglst, long));
}

print_ll(va_list arglst)
{
    ft_putnbr_ll(va_arg(arglst, long long));
}