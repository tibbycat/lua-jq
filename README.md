# lua-jq
Allow us to call jq from kong for response transformation.
Built on Kong CE 0.14.
## Prerequisites
jq-devel if you're on RHEL7
```
$ sudo yum install jq-devel
```
## Installing
Build and install lua-jq
```
1. git clone https://github.com/tibbycat/lua-jq.git
2. make
3. ./jq-test.lua
4. sudo cp jq.so /usr/local/lib/lua/5.1
```
## Needs work if you want to support chunking
