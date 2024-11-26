.PHONY	:	clean fclean re all client server

#			GCC

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE) -I$(PRINTF)include
INCLUDE 	=	includes

#			CLIENT

CSRC_FILES	=	main
CSRC_DIR	=	client/
COBJ_DIR	=	cobj/
CSRC 		= 	$(addprefix $(CSRC_DIR), $(addsuffix .c, $(CSRC_FILES)))
COBJ 		= 	$(addprefix $(COBJ_DIR), $(addsuffix .o, $(CSRC_FILES)))

#			SERVER

SSRC_FILES	=	main
SSRC_DIR	=	server/
SOBJ_DIR	=	sobj/
SSRC 		= 	$(addprefix $(SSRC_DIR), $(addsuffix .c, $(SSRC_FILES)))
SOBJ 		= 	$(addprefix $(SOBJ_DIR), $(addsuffix .o, $(SSRC_FILES)))

#			LIBFTPRINTF

PRINTF		=	ft_printf/
PRINTF_A	=	$(addprefix $(PRINTF), libftprintf.a)

#			RULES

all		:	client server

client	:	$(COBJ_DIR) $(COBJ)
	$(CC) $(CFLAGS) $(COBJ) -L$(PRINTF) -lftprintf -o client_soft

server	:	$(PRINTF_A) $(SOBJ_DIR) $(SOBJ)
	$(CC) $(CFLAGS) $(SOBJ) -L$(PRINTF) -lftprintf -o server_soft

$(PRINTF_A):
	$(MAKE) -s -C $(PRINTF)

$(COBJ_DIR):
	mkdir $(COBJ_DIR)

$(SOBJ_DIR):
	mkdir $(SOBJ_DIR)

$(COBJ_DIR)%.o: $(CSRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SOBJ_DIR)%.o: $(SSRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) -rf $(COBJ_DIR) $(SOBJ_DIR)
	$(MAKE) clean -s -C $(PRINTF)

fclean	:	clean
	$(RM) -f client server
	$(MAKE) fclean -s -C $(PRINTF)

re		:	fclean all