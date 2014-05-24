NAME		= libdynbuf.a

ifndef CC
    CC		= /usr/bin/gcc
endif

CFLAGS   = -Wall -Wextra
ifeq ($(config), debug)
    CFLAGS	+= -g3
else
    CFLAGS	+= -Werror
endif

INCDIR		= inc
SRCDIR		= src
OBJDIR		= obj
SRC			= dynbuf_new.c dynbuf_del.c dynbuf_write.c dynbuf_clear.c \
			  dynbuf_insert.c dynbuf_pop.c dynbuf_tostr.c dynbuf_dup.c \
			  private_functions.c

OBJ			= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	$(CC) -I$(INCDIR) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
