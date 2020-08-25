LUA_DIR=/usr/local
LUA_LIBDIR=$(LUA_DIR)/lib/lua/5.1
LUA_SHAREDIR=$(LUA_DIR)/share/lua/5.1
CC=gcc
INCDIRS=/usr/local/openresty/luajit/include/luajit-2.1
LIBDIRS=/usr/local/openresty/luajit/lib/
FLAGS=-Wall -shared -fPIC -Wl,-R,$(LIBDIRS)
LIBS=luajit-5.1
jq.so: lua-jq.c
	$(CC) $(FLAGS) -o $@ -I$(INCDIRS) -L$(LIBDIRS) -l$(LIBS) -ljq $<

install:
	cp jq.so $(LUA_LIBDIR)


