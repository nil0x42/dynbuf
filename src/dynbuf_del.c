#include <stdlib.h>
#include "dynbuf.h"

void		dynbuf_del(t_dynbuf **buf)
{
	if (*buf == NULL)
		return ;
	free((*buf)->ptr);
	free(*buf);
	*buf = NULL;
}
