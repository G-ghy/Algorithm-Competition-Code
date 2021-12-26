sudo ovs-vsctl add-port ovs-switch p1 -- set Interface p1 ofport_request=101
sudo ovs-vsctl set Interface p1 type=internal
sudo ip netns add ns1
sudo ip link set p1 netns ns1
sudo ip netns exec ns1 ip addr add 172.16.15.101/24 dev p1
sudo ip netns exec ns1 ifconfig p1 promisc u


sudo ovs-vsctl add-port ovs-switch p2 -- set Interface p2 ofport_request=102
sudo ovs-vsctl set Interface p2 type=internal
sudo ip netns add ns2
sudo ip link set p2 netns ns2
sudo ip netns exec ns2 ip addr add 172.16.15.102/24 dev p2
sudo ip netns exec ns2 ifconfig p2 promisc up

sudo ovs-vsctl show


sudo ovs-ofctl show ovs-switch

sudo ovs-vsctl get Interface p0 ofport

sudo ovs-vsctl get Interface p1 ofport

sudo ovs-vsctl get Interface p2 ofport

sudo ovs-dpctl show

sudo ip netns exec ns0 ping 172.16.15.100
sudo ip netns exec ns0 ping 172.16.15.101
sudo ip netns exec ns0 ping 172.16.15.102

sudo ovs-appctl fdb/show ovs-switch

sudo ovs-ofctl dump-tables ovs-switch

ovs-ofctl dump-flows ovs-switch

ovs-ofctl del-flows ovs-switch "in_port=100"

ovs-ofctl show ovs-switch


sudo ip netns exec ns0 ip addr del 172.16.15.146/24 dev p0
sudo ip netns exec ns1 ip addr del 172.16.15.146/24 dev p1
sudo ip netns exec ns2 ip addr del 172.16.15.146/24 dev p2

sudo ip netns exec ns0 ip addr show
sudo ip netns exec ns1 ip addr show
sudo ip netns exec ns2 ip addr show

sudo ovs-ofctl add-flow ovs-switch "table=0, dl_src=01:00:00:00:00:00/01:00:00:00:00:00, actions=drop"

sudo ovs-ofctl add-flow ovs-switch "table=0, dl_dst=01:80:c2:00:00:00/ff:ff:ff:ff:ff:f0, actions=drop"

sudo ovs-ofctl add-flow ovs-switch "priority=1, idle_timeout=0, in_port=100, actions=mod_nw_src:9.181.137.1, normal"

sudo ip netns exec ns0 ping 172.16.15.101

sudo ip netns exec ns1 tcpdump -i p1 icmp

sudo ip netns exec ns0 ping 172.16.15.101

sudo ip netns exec ns2 tcpdump -i p2 icmp

sudo ovs-ofctl add-flow ovs-switch idle_timeout=0,dl_type=0x0800,nw_proto=1,actions=output:102



sudo ovs-vsctl set Port p1 tag=101

sudo ovs-appctl ofproto/trace ovs-switch in_port=100,dl_src=2a:be:da:0e:7b:33,dl_dst=c2:ef:af:fb:27:9d -generate

sudo ovs-ofctl add-flow ovs-switch "priority=3,in_port=100,dl_vlan=0xffff,actions=mod_vlan_vid:101,normal"

sudo ovs-appctl ofproto/trace ovs-switch
in_port=101,dl_src=f2:0d:06:ff:79:d7,dl_dst=d6:0f:7e:ed:11:e4 -generat

sudo ovs-appctl ofproto/trace ovs-switch in_port=101,dl_src=c2:ef:af:fb:27:9d,dl_dst=2a:be:da:0e:7b:33 -generate


sudo ovs-vsctl set-controller ovs-switch tcp:172.16.15.146:6653

sudo ovs-vsctl set Bridge ovs-switch fail-mode=secure

sudo ovs-vsctl show


sudo curl -X POST -d '{"switch": "00:00:56:70:35:0a:5b:4d", "name":"my-flow1", "cookie":"0","priority":"32768","in_port":"100","active":"true", "actions":"output=flood"}' http://127.0.0.1:8080/wm/staticflowentrypusher/json

sudo curl -X POST -d '{"switch": "00:00:56:70:35:0a:5b:4d","name":"my-flow2", "cookie":"0","priority":"32768","in_port":"101","active":"true","actions":"output=flood"}' http://127.0.0.1:8080/wm/staticflowentrypusher/json


sudo curl http://127.0.0.1:8080/wm/staticflowentrypusher/json


sudo curl http://127.0.0.1:8080/wm/staticflowentrypusher/list/all/json | python -mjson.tool


sudo ip netns exec ns0 ping -c4 172.16.15.101


sudo ovs-ofctl dump-flows ovs-switch