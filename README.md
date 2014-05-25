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

t_dynbuf *dynbuf_new(int radix);
t_dynbuf *dynbuf_dup(const t_dynbuf *buf);
void     dynbuf_del(t_dynbuf **buf);
void     dynbuf_clear(t_dynbuf *buf);
int      dynbuf_write(t_dynbuf *buf, const void *data, int datasz);
int      dynbuf_insert(t_dynbuf *buf, int pos, const void *data, int datasz);
int      dynbuf_pop(t_dynbuf *buf, int pos, int datasz);
char     *dynbuf_tostr(t_dynbuf *buf);

```
