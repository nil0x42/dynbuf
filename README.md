### dynbuf: An ANSI C lightweight dynamic buffer library

The dynbuf library provides a dynamic memory buffer abstraction
which provides writing, insertion and partial/total removal
without worrying about memory management.

------------------------------------------------------------------------
#### Quick start

    cd my_c_project
    git clone https://github.com/nil0x42/dynbuf.git
    ./dynbuf/demo/run_demo.sh

------------------------------------------------------------------------
#### Interface
```c

typedef struct	s_dynbuf
{
    void        *ptr;
    size_t      size;
    size_t      offset;
    size_t      radix;
}               t_dynbuf;

// Returns a freshly allocated dynbuf that expands according to `radix`, or NULL it it fails.
t_dynbuf        *dynbuf_new(int radix);

// Returns a full copy of the given dynbuf, or NULL if it fails.
t_dynbuf        *dynbuf_dup(const t_dynbuf *buf);

// Free the given dynbuf, and make it point to NULL.
void            dynbuf_del(t_dynbuf **buf);

// Put dynbuf's offset to zero, allowing overwrite without realocation.
void            dynbuf_clear(t_dynbuf *buf);

// Write `datasz` bytes from `data` to dynbuf, using dynbuf->offset as position.
// Returns the amount of written bytes, or -1 if it fails.
int             dynbuf_write(t_dynbuf *buf, const void *data, int datasz);

// Insert `datasz` bytes from `data` to dynbuf, starting at `pos`.
// Returns the amout of inserted bytes, or -1 if it fails.
int             dynbuf_insert(t_dynbuf *buf, int pos, const void *data, int datasz);

// Remove `datasz` bytes from dynbuf, starting at `pos`.
// Returns the amout of removed bytes, or -1 if it fails.
int             dynbuf_pop(t_dynbuf *buf, int pos, int datasz);

// Returns a null-terminated string copy of dynbuf's data, or NULL if it fails.
char            *dynbuf_tostr(t_dynbuf *buf);

```
