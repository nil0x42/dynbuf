/*
** The dynbuf.h header file provides the library's public
** interface. It contains all available t_dynbuf handling functions
** For more informations about functions behavior, take a look
** at the README.md file at dynbuf's root path.
*/

#ifndef DYNBUF_H
# define DYNBUF_H

# include "dynbuf_struct.h"

# define DYNBUF_DEFAULT_RADIX 32

t_dynbuf	*dynbuf_new(int radix);
t_dynbuf	*dynbuf_dup(const t_dynbuf *buf);
void		dynbuf_del(t_dynbuf **buf);
void		dynbuf_clear(t_dynbuf *buf);
int			dynbuf_write(t_dynbuf *buf, const void *data, int datasz);
int			dynbuf_insert(t_dynbuf *buf, int pos, const void *data, int datasz);
int			dynbuf_pop(t_dynbuf *buf, int pos, int datasz);
char		*dynbuf_tostr(t_dynbuf *buf);

#endif
