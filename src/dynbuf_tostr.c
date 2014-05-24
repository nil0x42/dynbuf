#include <stdlib.h>
#include "dynbuf.h"
#include "dynbuf_private.h"

char		*dynbuf_tostr(t_dynbuf *buf)
{
	char	*str;

	str = (char*)malloc(buf->offset + 1);
	if (str == NULL)
		return (NULL);
	dynbuf_priv_memcpy(str, buf->ptr, buf->offset);
	str[buf->offset] = '\0';
	return (str);
}
