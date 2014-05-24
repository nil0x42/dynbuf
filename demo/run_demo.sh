#!/bin/sh

DYNBUF_DIR=".."
EXEC_DEMO="dynbuf_demo"

make -C $DYNBUF_DIR
gcc demo.c -o $EXEC_DEMO -I$DYNBUF_DIR/inc -L$DYNBUF_DIR -ldynbuf
echo "====================== DEMO.C ======================="
highlight -O ansi demo.c 2>/dev/null || cat demo.c
echo "====================================================="
./$EXEC_DEMO

