/*
** The dynbuf.h header file provides the library's public
** interface. It contains all available t_dynbuf handling functions
** For more informations about functions behavior, take a look
** at the README.md file at dynbuf's root path.
*/

#ifndef DYNBUF_H
# define DYNBUF_H

# include <stddef.h>

# define DYNBUF_DEFAULT_RADIX 32

typedef struct	s_dynbuf
{
	void		*ptr;
	size_t		size;
	size_t		offset;
	size_t		radix;
}				t_dynbuf;

/*
** Returns a freshly allocated dynbuf that expands according to `radix`, or NULL it it fails.
*/
t_dynbuf		*dynbuf_new(int radix);

/*
** Returns a full copy of the given dynbuf, or NULL if it fails.
*/
t_dynbuf		*dynbuf_dup(const t_dynbuf *buf);

/*
** Free the given dynbuf, and make it point to NULL.
*/
void			dynbuf_del(t_dynbuf **buf);

/*
** Put dynbuf's offset to zero, allowing overwrite without realocation.
*/
void			dynbuf_clear(t_dynbuf *buf);
/*
** Write `datasz` bytes from `data` to dynbuf, using dynbuf->offset as position.
** Returns the amount of written bytes, or -1 if it fails.
*/
int				dynbuf_write(t_dynbuf *buf, const void *data, int datasz);

/*
** Insert `datasz` bytes from `data` to dynbuf, starting at `pos`.
** Returns the amout of inserted bytes, or -1 if it fails.
*/
int				dynbuf_insert(t_dynbuf *buf, int pos,
								const void *data, int datasz);

/*
** Remove `datasz` bytes from dynbuf, starting at `pos`.
** Returns the amout of removed bytes, or -1 if it fails.
*/
int				dynbuf_pop(t_dynbuf *buf, int pos, int datasz);

/*
** Returns a null-terminated string copy of dynbuf's data, or NULL if it fails.
*/
char			*dynbuf_tostr(t_dynbuf *buf);

#endif
