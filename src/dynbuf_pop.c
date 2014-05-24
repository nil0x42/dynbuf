#include "dynbuf.h"
#include "dynbuf_private.h"

int			dynbuf_pop(t_dynbuf *buf, int pos, int datasz)
{
	char	*gap;

	if (buf == NULL || datasz < 0)
		return (-1);
	if (pos > buf->offset)
		return (-1);
	if (pos < 0)
		pos += buf->offset + 1;
	if (pos < 0)
		return (-1);
	if ((pos + datasz) < buf->offset)
	{
		gap = (char*)buf->ptr + pos;
		dynbuf_priv_memcpy(gap, gap + datasz, datasz);
	}
	buf->offset -= datasz;
	return (buf->offset);
}
