.PHONY	:	clean fclean re all

#			GCC

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE) -I$(PRINTF)include
INCLUDE 	=	includes

#			CLIENT

CSRC_FILES	=	client
CSRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CSRC_FILES)))
COBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CSRC_FILES)))

#			SERVER

SSRC_FILES	=	server
SSRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SSRC_FILES)))
SOBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SSRC_FILES)))

#			COMMON

SRC_DIR	=	src/
OBJ_DIR	=	$(SRC_DIR)obj/

#			LIBFTPRINTF

PRINTF		=	ft_printf/
PRINTF_A	=	$(PRINTF)libftprintf.a

#			RULES

all		:	client server

client	:	$(OBJ_DIR) $(COBJ) $(PRINTF_A) $(INCLUDE)/client.h
	$(CC) $(CFLAGS) $(COBJ) -L$(PRINTF) -lftprintf -o client

server	:	$(OBJ_DIR) $(SOBJ) $(PRINTF_A) $(INCLUDE)/server.h
	$(CC) $(CFLAGS) $(SOBJ) -L$(PRINTF) -lftprintf -o server

$(PRINTF_A):
	$(MAKE) -C $(PRINTF)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) clean -s -C $(PRINTF)

fclean	:	clean
	$(RM) -f client server
	$(MAKE) fclean -s -C $(PRINTF)

re		:	fclean all