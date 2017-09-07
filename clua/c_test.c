/* 
 * file: c_test.c 
 */  



// #include <lua.h>  
// #include <lauxlib.h>  
// #include <lualib.h>

#include <string.h>  
#include <unistd.h>  
#include <stdio.h>  
  
#include        "lua.h"
#include        "lualib.h"
#include        "lauxlib.h"

int get_tab(lua_State *L)  
{  
    /* create table. */  
    lua_newtable(L);  
  
    /* push (key, value). */  
    int i;  
    char value[10] = {0};  
    for(i=0; i<5; ++i)  
    {  
        sprintf(value, "value%d", i+1);  
        lua_pushnumber(L, i+1);    //key  
        lua_pushstring(L, value);  //value  
        lua_settable(L, -3);       //push key,value  
    }  
  
    /* deal return. */  
    return 1;  
}  
  
int main()  
{  
    /* create a state and load standard library. */  
    lua_State* L = luaL_newstate();  
  
    /* opens all standard Lua libraries into the given state. */  
    luaL_openlibs(L);  
  
    /* register function be called by lua. */  
    lua_register(L, "gettab", get_tab);  
  
    /* load and exec the specified lua file. */  
    int error = luaL_dofile(L, "lua_test.lua");  
    if(error) {  
        perror("luaL_dofile error");  
        // exit(1);  
        return 0;
    }  
  
    /* get the domain function from lua file. */   
    lua_getglobal(L,"domain");  
  
    /* exec the domain function. */  
    error = lua_pcall(L, 0, 0, 0);  
    if (error) {  
        fprintf(stderr,"%s\n",lua_tostring(L,-1));  
        lua_pop(L,1);  
    }  
  
    /* close lua state. */  
    lua_close(L);  
  
    return 0;  
}  