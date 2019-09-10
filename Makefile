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

OBJ = ft_printf.o conv_int.o conv_uns.o ft_convbase.o print.o ft_get_double.o \
	flag_getters.o apply_mods.o process_flags.o

LIBFTOBJ = ft_str_resize.o \
	ft_memrcpy.o ft_lst_append.o ft_lstmap.o ft_lstdelone.o ft_lstdel.o \
	ft_lstadd.o ft_lstiter.o ft_lstnew.o ft_putendl.o ft_putchar_fd.o \
	ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_itoa.o ft_strsplit.o\
	ft_strtrim.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o \
	ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o \
	ft_strsub.o ft_strjoin.o ft_memalloc.o ft_atoi.o ft_isspace.o ft_strrchr.o \
	ft_strlcat.o ft_memmove.o ft_memcmp.o ft_memccpy.o ft_memchr.o ft_memcpy.o \
	ft_bzero.o ft_memset.o ft_strlen.o ft_putnbr.o ft_putstr.o ft_strdup.o \
	ft_strcpy.o ft_strncpy.o ft_strchr.o ft_strcat.o ft_strncat.o ft_strstr.o \
	ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
	ft_isupper.o ft_islower.o ft_putchar.o ft_power.o ft_strcaps.o

INCL = libft/includes

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTOBJ)
	ar rc $(NAME) $(OBJ) $(LIBFTOBJ)

%.o: %.c
	gcc -c -o $@ $^ -I $(INCL)

%.o: libft/%.c
	gcc -Wall -Wextra -Werror -c -o $@ $^ -I $(INCL)

test: $(NAME) main.c
	gcc -o $@ -Wall -Wextra -Werror main.c $(NAME) -I $(INCL)

test2: $(NAME) test.c ft_bin.c
	gcc -o $@ -Wall -Wextra -Werror test.c ft_bin.c $(NAME) -I $(INCL)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all