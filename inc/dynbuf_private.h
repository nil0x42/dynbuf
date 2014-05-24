/*
** The dynbuf_private.h header provides internally used
** functions which are not part of the public interface.
*/

#ifndef DYNBUF_PRIVATE_H
# define DYNBUF_PRIVATE_H

void	*dynbuf_priv_memcpy(void *dest, const void *src, size_t n);
void	*dynbuf_priv_memmove(void *s1, const void *s2, size_t n);

#endif
