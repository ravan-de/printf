#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ravan-de <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/21 15:13:41 by ravan-de      #+#    #+#                  #
#    Updated: 2019/04/29 18:44:14 by ravan-de      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

OBJ = ft_printf.o

INCL = libft/includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

test: $(OBJ)
	gcc -o test -Wall -Wextra -Werror $(OBJ) libft/libft.a

printf:
	gcc -o test -Wall -Wextra -Werror test.c libft/libft.a

%.o: %.c
	gcc -c -Wall -Wextra -Werror -I $(INCL) $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

doei: fclean
	rm -f *~

re: fclean all