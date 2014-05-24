#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "dynbuf.h"

int     main(void)
{
	t_dynbuf    *dynbuf;
	char        *str;

	// create a dynbuf that expands itself 10 by 10 octets when needed.
	dynbuf = dynbuf_new(10);

	// write 3 octets from "stream" to the end of dynbuf.
	dynbuf_write(dynbuf, "stream", 3);

	// a size of -1 assumes that data is an unix str, and copies it entirely.
	dynbuf_write(dynbuf, "ing", -1);

	// we could make use of dynbuf's ptr and offset to output it.
	write(1, dynbuf->ptr, dynbuf->offset);
	write(1, "\n", 1);
	printf("%d\n", dynbuf->offset);

	// insert "foo" at the start of the buffer (position 0)
	dynbuf_insert(dynbuf, 0, "foo", -1);

	write(1, dynbuf->ptr, dynbuf->offset);
	write(1, "\n", 1);
	printf("%d\n", dynbuf->offset);

	// remove 4 chars at potition 2
	dynbuf_pop(dynbuf, 2, 4);

	// output a fresh unix string copy of dynbuf's data.
	str = dynbuf_tostr(dynbuf);
	puts(str);
	free(str);

	// free the dynbuf's allocated memory
	dynbuf_del(&dynbuf);

	return (0);
}
