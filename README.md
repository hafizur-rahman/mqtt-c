mqtt-c
======

0. Install necessary C libray
=============================
Paho C client library is used which can be built for Linux/Unix/Mac with make and gcc. To build:
```
git clone http://git.eclipse.org/gitroot/paho/org.eclipse.paho.mqtt.c.git
cd org.eclipse.paho.mqtt.c.git
make
```
To install:
```
sudo make install
```

For further details, please consult http://www.eclipse.org/paho/clients/c/.

1. Build current project
========================
```
make
```

To install:
```
sudo make install
```
Two binaries (mqtt-pub, mqtt-sub) will be installed at /usr/local/bin.

2. Install & run MQTT Broker
============================
See https://github.com/hafizur-rahman/mqtt/blob/master/README.md

3. Run Subscriber
================
```
/usr/local/bin/mqtt-sub
```

4. Run Publisher
================
```
/usr/local/bin/mqtt-pub
```

Detailed documentation regarding Paho C client library can be found at http://www.eclipse.org/paho/files/mqttdoc/Cclient/index.html
