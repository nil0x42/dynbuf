#include <stdlib.h>
#include "dynbuf.h"

t_dynbuf	*dynbuf_new(int radix)
{
	t_dynbuf	*buf;

	buf = (t_dynbuf*)malloc(sizeof(t_dynbuf));
	if (buf == NULL)
		return (NULL);
	if (radix < 1)
		radix = DYNBUF_DEFAULT_RADIX;
	buf->radix = radix;
	buf->ptr = NULL;
	buf->size = 0;
	buf->offset = 0;
	return (buf);
}
