#include <stddef.h>

void	*dynbuf_priv_memcpy(void *s1, const void *s2, size_t n)
{
	char		*dst;
	const char	*src;

	dst = (char*)s1;
	src = (const char*)s2;
	while (n--)
		*dst++ = *src++;
	return (s1);
}

void	*dynbuf_priv_memmove(void *s1, const void *s2, size_t n)
{
	char		*dst;
	const char	*src;

	if (s1 == NULL || s2 == NULL || s1 == s2 || n == 0)
		return (s1);
	dst = (char*)s1;
	src = (const char*)s2;
	if (src < dst && (src + n) > dst)
	{
		dst += n - 1;
		src += n - 1;
		while (n--)
			*dst-- = *src--;
	}
	else
		dynbuf_priv_memcpy(s1, s2, n);
	return (s1);
}
