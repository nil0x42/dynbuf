#include <stdlib.h>
#include "dynbuf.h"
#include "dynbuf_private.h"

t_dynbuf		*dynbuf_dup(const t_dynbuf *buf)
{
	t_dynbuf		*new;

	new = (t_dynbuf*)malloc(sizeof(t_dynbuf));
	if (new == NULL)
		return (NULL);
	dynbuf_priv_memcpy(new, buf, sizeof(t_dynbuf));
	new->ptr = malloc(buf->size);
	if (new->ptr == NULL)
		return (NULL);
	dynbuf_priv_memcpy(new->ptr, buf->ptr, buf->size);
	return (new);
}
