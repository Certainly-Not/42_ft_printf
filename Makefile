NAME 	= libftprintf.a

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

SRC_DIR := srcs
OBJ_DIR	:= objs

SOURCES	:=	$(wildcard $(SRC_DIR)/*.c) 
OBJECTS	:=	$(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar -rc $(NAME) $^
	ranlib $(NAME)

$(OBJECTS) : $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $^: "
	@$(CC) -c $(CFLAGS) -c $< -o $@
	@echo "✓"

clean :
	@echo "Cleaning up..."
	@rm -f $(OBJ_DIR)/*.o

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re