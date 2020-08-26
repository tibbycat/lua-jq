# lua-jq
Allow us to call jq from kong for request and/or response transformation.
Built on Kong CE 0.14.
## Prerequisites
. gcc
. jq-devel if you're on RHEL7
```
$ sudo yum install jq-devel
```
. libjq-dev if you're on Debian
```
$ sudo apt install libjq-dev
```
## Installing
### Quick
```
$ sudo luarocks install lua-jq
```
### Old hat
Build and install lua-jq
```
1. git clone https://github.com/tibbycat/lua-jq.git
2. make
3. make test
4. sudo make install
```
## Needs work if you want to support chunking
