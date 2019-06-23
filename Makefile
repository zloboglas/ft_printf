# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    newMakefile                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 14:44:36 by dlabadie          #+#    #+#              #
#    Updated: 2019/05/04 10:16:36 by dlabadie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = ft_printf.out

#SRCS = ft_printf.c ft_realloc.c parser.c unsigned_flags.c \
#double.c double_printing.c libpf.c \
#more_then_helpers.c rounding.c counting.c doubtopair.c helpers_for_double.c

OBJS := ft_printf.o
OBJS += counting.o double_printing.o doubtopair.o helpers_for_double.o more_then_helpers.o rounding.o
OBJS += help_for_pars.o parser.o parser_help.o
OBJS += double.o print_char.o print_decimal.o print_hex.o print_int.o print_octal.o print_string.o print_per.o printing_sim.o octal_helpers.o more_octal_helpers.o hex_helpers.o more_hex_helpers.o last_hex_helpers.o
OBJS += pf_switch.o
OBJS += write_unsigned.o write_char.o write_decimal.o write_double.o write_hex.o write_int.o write_octal.o write_pointer.o write_string.o write_per.o get_unsigned.o get_signed.o




CC		= gcc
FLAGS	= -Wall -Wextra -Werror
#FLAGS =


FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/
FT_LNK	= -L ./libft -lft

SDIR	= ./src/
SDODIR	= ./src/doubles/
SPADIR	= ./src/parser/
SPRDIR	= ./src/prints/
SSWDIR	= ./src/switch/
SWRDIR	= ./src/writes/

IDIR	= ./includes/
ODIR	= ./obj/

OFILES		= $(addprefix $(ODIR),$(OBJS))

CFILES		:= $(addprefix $(SDIR), ft_printf.c)
CFILES      += $(addprefix $(SDODIR), counting.c double_printing.c doubtopair.c helpers_for_double.c more_then_helpers.c rounding.c)
CFILES      += $(addprefix $(SPADIR), help_for_pars.c parser.c parser_help.c)
CFILES      += $(addprefix $(SPRDIR), double.c print_char.c print_decimal.c print_hex.c print_int.c print_octal.c print_string.c print_per.c printing_sim.c octal_helpers.c more_octal_helpers.c hex_helpers.c more_hex_helpers.c last_hex_helpers.c)
CFILES      += $(addprefix $(SSWDIR), pf_switch.c)
CFILES      += $(addprefix $(SWRDIR), write_unsigned.c write_char.c write_decimal.c write_double.c write_hex.c write_int.c write_octal.c write_pointer.c write_string.c write_per.c get_unsigned.c get_signed.c)


all: $(NAME)

obj:
	mkdir $(ODIR)



$(ODIR)%.o:$(SDIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(IDIR) -o $@ -c $<

$(ODIR)%.o:$(SDODIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(IDIR) -o $@ -c $<

$(ODIR)%.o:$(SPADIR)%.c
	gcc $(FLAGS)  $(FT_INC) -I $(IDIR) -o $@ -c $<

$(ODIR)%.o:$(SPRDIR)%.c
	gcc $(FLAGS)  $(FT_INC) -I $(IDIR) -o $@ -c $<

$(ODIR)%.o:$(SSWDIR)%.c
	gcc $(FLAGS)  $(FT_INC) -I $(IDIR) -o $@ -c $<

$(ODIR)%.o:$(SWRDIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(IDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): obj $(FT_LIB) $(OFILES)
	cp $(FT_LIB) ./$(NAME)
	ar -rc $(NAME) $(OFILES)
	ranlib $(NAME)


test:
	gcc -g -I./includes/ $(FT_INC) -L. -lftprintf  run/printf.c -o $(TEST)


clean:
	rm -fr $(ODIR)*.o
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY : all clean fclean re test

