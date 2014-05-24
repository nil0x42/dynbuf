#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "dynbuf.h"

#define SHOW(b) (printf("offset: %d\tptr: '%.*s'\n",b->offset,b->offset,b->ptr))

int     main(void)
{
	t_dynbuf    *dynbuf;
	char        *str;

	// create a dynbuf that expands itself 10 by 10 octets when needed.
	dynbuf = dynbuf_new(10);
	SHOW(dynbuf);

	// write 3 octets from "stream" to the end of dynbuf.
	dynbuf_write(dynbuf, "stream", 3);
	SHOW(dynbuf);

	// a size of -1 assumes that data is an unix str, and copies it entirely.
	dynbuf_write(dynbuf, "ing", -1);
	SHOW(dynbuf);

	// insert "foo" at the start of the buffer (position 0)
	dynbuf_insert(dynbuf, 0, "foo", -1);
	SHOW(dynbuf);

	// remove 4 chars at potition 2
	dynbuf_pop(dynbuf, 2, 4);
	SHOW(dynbuf);

	// output a fresh unix string copy of dynbuf's data.
	str = dynbuf_tostr(dynbuf);
	puts(str);
	free(str);

	// free the dynbuf's allocated memory (also sets dynbuf to NULL).
	dynbuf_del(&dynbuf);

	return (0);
}
