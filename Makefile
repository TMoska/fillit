# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoska <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 11:03:20 by tmoska            #+#    #+#              #
#    Updated: 2016/11/23 21:25:20 by tmoska           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC 		= cc
NAME 		= fillit
FLAGS 		= -Wall -Werror -Wextra

LIB_PATH	= libft
LIB			= $(LIB_PATH)/libft.a
LIB_LINK	= -L $(LIB_PATH) -lft

INC_DIR		= includes
INC_FLAGS	= -I./includes -I $(LIB_PATH)/includes

SRC_DIR 	= src
SRC_FILES 	= 	main.c 	\
				utils.c \
				exits.c
SOURCES 	= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		= obj
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: obj $(NAME)

$(NAME): $(LIB) $(OBJECTS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "\033[0;32mSuccess: \033[0mfillit compiled"
	@echo "\033[0;32mDone"

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@$(CC) $(FLAGS) $(INC_FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@find . \( -name "*~" -o -name "*.swp" -o -name ".DS_Store" \) -delete
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	
re: fclean all
