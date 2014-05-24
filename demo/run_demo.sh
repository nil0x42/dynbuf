#!/bin/sh

DYNBUF_DIR=".."
DEMO_SRC="demo.c"
DEMO_BIN="dynbuf_demo"

cd $(dirname $0)

make -C $DYNBUF_DIR
gcc $DEMO_SRC -o $DEMO_BIN -I$DYNBUF_DIR/inc -L$DYNBUF_DIR -ldynbuf
echo "====================== $DEMO_SRC ======================="
highlight -O ansi "$DEMO_SRC" 2>/dev/null || cat "$DEMO_SRC"
echo "====================================================="
./$DEMO_BIN

cd - > /dev/null
