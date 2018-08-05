#!/usr/bin/lua
require("jq")
p= [=[.server]=]
j= [[{"database":{"reachable":true},"server":{"connections_writing":1,"total_requests":1715,"connections_handled":1712,"connections_accepted":1712,"connections_reading":0,"connections_active":1,"connections_waiting":0}}]]
r=jq(p,j)
print(r);
r=jq("isnan","NaN")
print(r);
r=jq("isinfinite","Inf")
print(r);
-- Test invalid json
p= [=[.server]=]
j= [[{"database":{"]]
r=jq(p,j)
print(r);

