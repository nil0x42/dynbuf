/*
** The dynbuf_struct.h header defines t_dynbuf (struct s_dynbuf)
** which represents dynamic buffers in the dynbuf library.
*/

#ifndef DYNBUF_STRUCT_H
# define DYNBUF_STRUCT_H

# include <stddef.h>

typedef struct	s_dynbuf
{
	void		*ptr;
	size_t		size;
	size_t		offset;
	size_t		radix;
}				t_dynbuf;

#endif
