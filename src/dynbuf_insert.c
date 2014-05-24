#include <stdlib.h>
#include "dynbuf.h"
#include "dynbuf_private.h"

static void	*static_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	if (old_size == 0)
		return (new);
	if (new_size < old_size)
		old_size = new_size;
	dynbuf_priv_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}

static int	static_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

static int	buf_divide(t_dynbuf *buf, int pos, int datasz)
{
	char	*gap;

	if (pos > (int)buf->offset)
		return (-1);
	if (pos < 0)
		pos += buf->offset + 1;
	if (pos < 0)
		return (-1);
	if (pos < (int)buf->offset)
	{
		gap = ((char*)buf->ptr) + pos;
		dynbuf_priv_memmove((gap + datasz), gap, buf->offset);
	}
	return (pos);
}

static int	buf_expand(t_dynbuf *buf, int datasz)
{
	int		newsz;

	while ((buf->offset + datasz) > buf->size)
	{
		newsz = buf->size + buf->radix;
		buf->ptr = (char*)static_realloc(buf->ptr, buf->size, newsz);
		if (buf->ptr == NULL)
			return (-1);
		buf->size = newsz;
	}
	return (0);
}

int			dynbuf_insert(t_dynbuf *buf, int pos, const void *data, int datasz)
{
	int		idx;

	if (buf == NULL || data == NULL)
		return (-1);
	if (datasz < 0)
		datasz = static_strlen(data);
	if (datasz == 0)
		return (0);
	if (buf_expand(buf, datasz) < 0)
		return (-1);
	pos = buf_divide(buf, pos, datasz);
	if (pos < 0)
		return (-1);
	idx = 0;
	while (idx < datasz)
	{
		((char*)(buf->ptr))[pos] = ((char*)data)[idx];
		pos += 1;
		idx += 1;
	}
	buf->offset += datasz;
	return (idx);
}
