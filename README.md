Hans - IP over ICMP
===================

Hans makes it possible to tunnel IPv4 through ICMP echo packets, so you could call it a ping tunnel. This can be useful when you find yourself in the situation that your Internet access is firewalled, but pings are allowed.

http://code.gerade.org/hans/


new versions:
https://sourceforge.net/projects/hanstunnel/files/source/

use for compile:

```bash
sudo apt install make gmake gcc g++ net-tools
```
```
cd hans-1.1
```
```
make
```
```
sudo cp ./hans /usr/sbin/hans
```
___

for create ***SERVER*** use:
```bash
nano /etc/systemd/system/hans.service
```
insert
```
[Unit]
Description=Hans IP over ICMP Server
After=network.target

[Service]
ExecStart=/usr/sbin/hans -s 10.2.2.0 -p you-secret-password -d tun0 -a 10.2.2.1
Restart=always
User=root
Group=root
RestartSec=3
PIDFile=/var/run/hans.pid


[Install]
WantedBy=default.target
```
and add you service:
```
sudo systemctl daemon-reload
```
```
sudo systemctl enable hans.service
```
```
sudo systemctl start hans.service
```

___

for create ***CLIENT*** use:
```bash
nano /etc/systemd/system/hans.service
```
insert
```
[Unit]
Description=Hans IP over ICMP Client
After=network.target

[Service]
ExecStart=/usr/sbin/hans -c you-server.com -p you-secret-password -d tun100 -a 10.2.2.100
Restart=always
User=root
Group=root
RestartSec=3
PIDFile=/var/run/hans.pid


[Install]
WantedBy=default.target
```
and add you service:
```
sudo systemctl daemon-reload
```
```
sudo systemctl enable hans.service
```
```
sudo systemctl start hans.service
```
