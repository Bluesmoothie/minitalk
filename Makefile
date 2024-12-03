.PHONY	:	clean fclean re all

#			GCC

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDE) -I $(LIBFT)include
INCLUDE 	=	includes

#			CLIENT

CSRC_FILES	=	client
CSRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CSRC_FILES)))
COBJ 		= 	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(CSRC_FILES)))

#			SERVER

SSRC_FILES	=	server
SSRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SSRC_FILES)))
SOBJ 		= 	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SSRC_FILES)))

#			COMMON

SRC_DIR		=	src
OBJ_DIR		=	$(SRC_DIR)/obj

#			LIBFT

LIBFT		=	libft_ex
LIBFT_A		=	$(LIBFT)libft_ex.a

#			RULES

all				:	client server

client			:	$(LIBFT_A) $(OBJ_DIR) $(COBJ)
				$(CC) $(CFLAGS) $(COBJ) -L$(LIBFT) -lft_ex -o client

server			:	$(LIBFT_A) $(OBJ_DIR) $(SOBJ)
				$(CC) $(CFLAGS) $(SOBJ) -L$(LIBFT) -lft_ex -o server

$(LIBFT_A)		:
				$(MAKE) -C $(LIBFT)

$(OBJ_DIR)		:
				mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c $(INCLUDE)/client.h $(INCLUDE)/server.h
				$(CC) $(CFLAGS) -c $< -o $@

clean			:
				$(RM) -rf $(OBJ_DIR)
				$(MAKE) clean -s -C $(LIBFT)

fclean			:	clean
				$(RM) -f client server
				$(MAKE) fclean -s -C $(LIBFT)

re				:	fclean all