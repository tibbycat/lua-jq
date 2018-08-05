CC=gcc
INCDIRS=/usr/local/openresty/luajit/include/luajit-2.1
LIBDIRS=/usr/local/openresty/luajit/lib/
FLAGS=-Wall -shared -fPIC -Wl,-R,$(LIBDIRS)
LIBS=luajit-5.1
jq.so: lua-jq.c
	$(CC) $(FLAGS) -o $@ -I$(INCDIRS) -L$(LIBDIRS) -l$(LIBS) -ljq $<

