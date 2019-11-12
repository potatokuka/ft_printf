# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: greed <greed@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 10:31:09 by greed          #+#    #+#                 #
#    Updated: 2019/11/12 17:30:07 by greed         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME        =   libftprintf.a
CFILES      =   ft_printf.c ft_print_func.c ft_helper.c
OFILES      =   $(CFILES:.c=.o)
BONUS_SRCS  =	
BONUS_CFILES=	$(BONUS_SRCS:%=%.c)
BONUS_OFILES=	$(BONUS_CFILES:.c=.o)
LIBFT_PATH	=	./libft/
LIBFT_CFILES	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c\
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c\
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c\
	ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
LIBFT_OFILES=	$(LIBFT_CFILES:.c=.o)
FLAGS       =   -Wall -Werror -Wextra

# COLORS
PINK	= \x1b[35;01m
BLUE	= \x1b[34;01m
YELLOW	= \x1b[33;01m
GREEN	= \x1b[32;01m
RED		= \x1b[31;01m
WHITE	= \x1b[31;37m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT_OFILES:%=./libft/%)
	@echo "$(YELLOW)Linking the library"
	@ar rc $(NAME) $(OFILES) $(LIBFT_OFILES:%=./libft/%);
	@ranlib $(NAME)
	@echo "$(GREEN)Done"

%.o: %.c
	@echo "$(BLUE)Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) -I$(LIBFT_PATH)

clean: clean_b
	@echo "$(RED) Cleaning..."
	@rm -f $(OFILES)
	@rm -f $(LIBFT_OFILES:%=./libft/%)
	@rm -f $(BONUS_OFILES)

fclean: clean_b
	@echo "$(PINK)Big cleaning..."
	@rm -f $(NAME)

clean_b:
	@rm -f $(BOFILES)
	@rm -f $(OFILES)

re: fclean all

bonus: $(OFILES) $(BOFILES) $(NAME)
	@echo "$(YELLOW)Linking the bonusses into the library"
	@ar rc $(NAME) $(OFILES) $(BOFILES)
	@ranlib $(NAME)
	@echo "$(GREEN)Done"
