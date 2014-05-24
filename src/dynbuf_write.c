#include "dynbuf.h"

int			dynbuf_write(t_dynbuf *buf, const void *data, int datasz)
{
	return (dynbuf_insert(buf, -1, data, datasz));
}
