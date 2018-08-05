#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "jv.h"
#include "jq.h"

static int luajq(lua_State *L){              /* Internal name of func */

        const char *program = lua_tostring(L, 1);
        const char *data = lua_tostring(L, 2);

	/*
        printf("program=%s\n",program);
        printf("data=%s\n",data);
	printf("\n");
	*/

	jq_state *jq = NULL;
	//int flags=JQ_DEBUG_TRACE;
	int flags=0;
	jv js=jv_string("");
	
	jq=jq_init();
	if(jq_compile(jq, program)) {
		jv parsed=jv_parse(data);

		if(jv_is_valid(parsed)) {
			jq_start(jq, jv_parse(data), flags);
			jv result;
			while (jv_is_valid(result = jq_next(jq))) {
				js=jv_string_concat( js, jv_dump_string(result,flags) );
				//printf("debug: js=%s\n",jv_string_value(js));
			}
			jv_free(result);
		}
		jv_free(parsed);
	}

        lua_pushstring(L,jv_string_value(js));           /* Push the return */
	jv_free(js);
	jq_teardown(&jq);
	return 1;
}

/* Register this file's functions with the
 * luaopen_libraryname() function, where libraryname
 * is the name of the compiled .so output. In other words
 * it's the filename (but not extension) after the -o
 * in the cc command.
 *
 * So for instance, if your cc command has -o power.so then
 * this function would be called luaopen_power().
 *
 * This function should contain lua_register() commands for
 * each function you want available from Lua.
 *
*/
int luaopen_jq(lua_State *L){
        lua_register(
                        L,               /* Lua state variable */
                        "jq",        /* func name as known in Lua */
                        luajq          /* func name in this file */
                        );
        return 0;
}

