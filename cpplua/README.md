# cpp_demo

install lua


http://www.cnblogs.com/louis-tin/p/4856758.html

1.下载包

[root@louis ~]# wget http://www.lua.org/ftp/lua-5.3.1.tar.gz

2.解压缩

[root@louis lua]# tar zxf lua-5.3.1.tar.gz

3.修改Makefile文件

[root@louis]# cd lua-5.3.1

[root@louis lua-5.3.1]# vim Makefile

INSTALL_TOP= /usr/local/lua

4.运行安装

[root@louis lua-5.3.1]# make linux

make[1]: Entering directory `/usr/local/lua/lua-5.3.1/src'
make all SYSCFLAGS="-DLUA_USE_LINUX" SYSLIBS="-Wl,-E -ldl -lreadline -lncurses"
make[2]: Entering directory `/usr/local/lua/lua-5.3.1/src'
gcc -O2 -Wall -DLUA_COMPAT_ALL -DLUA_USE_LINUX -c -o lua.o lua.c
gcc -o lua lua.o liblua.a -lm -Wl,-E -ldl -lreadline -lncurses 
gcc -O2 -Wall -DLUA_COMPAT_ALL -DLUA_USE_LINUX -c -o luac.o luac.c
gcc -o luac luac.o liblua.a -lm -Wl,-E -ldl -lreadline -lncurses 
make[2]: Leaving directory `/usr/local/lua/lua-5.3.1/src'
make[1]: Leaving directory `/usr/local/lua/lua-5.3.1/src'

[root@dev lua-5.3.1]# make install

cd src && mkdir -p /usr/local/lua/bin /usr/local/lua/include /usr/local/lua/lib /usr/local/lua/man/man1 /usr/local/lua/share/lua/5.3 /usr/local/lua/lib/lua/5.3
cd src && install -p -m 0755 lua luac /usr/local/lua/bin
cd src && install -p -m 0644 lua.h luaconf.h lualib.h lauxlib.h lua.hpp /usr/local/lua/include
cd src && install -p -m 0644 liblua.a /usr/local/lua/lib
cd doc && install -p -m 0644 lua.1 luac.1 /usr/local/lua/man/man1

5.验证一下

[root@louis lua-5.3.1]# /usr/local/lua/bin/lua

Lua 5.3.1  Copyright (C) 1994-2015 Lua.org, PUC-Rio


> 
恭喜，安装成功了！


=========================================
http://www.cnblogs.com/chevin/p/6229739.html

④lua -v查看版本，发现还是旧的版本，那我们就将/usr/bin中的lua和luac删除，然后将/usr/local/bin中的lua和luac创建一个ln到/usr/bin中即可

cd /usr/bin

rm -rf lua luac

ln -s /usr/local/lua/bin/lua /usr/bin/lua

ln -s /usr/local/lua/bin/luac /usr/bin/luac

lua -v
===========================================

include file

http://blog.csdn.net/finded/article/details/50478779



