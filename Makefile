##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my make file
##

NAME	=	my_defender

SRCS	= 	./main.c \
			./src/button_click.c \
			./src/def.c \
			./src/init_turret.c \
			./src/loose_events.c \
			./src/other_init.c \
			./src/range_tower.c \
			./src/range_tower2.c \
			./src/update_enemy.c \
			./src/rotate.c \
			./src/root.c \
			./src/root2.c \
			./src/gold.c \
			./src/otherfun.c \
			./src/otherfun2.c \
			./src/otherfun3.c \
			./src/scene.c \
			./src/2range_tower2.c \
			./lib/my/intostring.c \
			./lib/my/revstr.c \

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

CC = gcc

RM	=	rm -f

CFLAGS += -I ./include/
CFLAGS += -W -Wall -Wextra -g3
CFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] ➢ \033[0m \033[1;36m$(NBR_OF_FILES)\033[0m"
		@ $(CC) -o $(NAME) $(OBJS) $(CFLAGS)
		@ echo "\033[1;34m●  The executable \033[1;39m$(NAME)\033[1;34m has been created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31m● Removing: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)

re: 	fclean all

%.o:	%.c
		@ echo "\033[1;34m[ OK √ ]\033[0m Compiling" $<
		@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
