#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "MQTTClient.h"
#include "callback.h"

#define ADDRESS     "tcp://127.0.0.1:61613"
#define CLIENTID    "paho-subscriber"
#define TOPIC       "lights"
#define QOS         1
#define TIMEOUT     100000L

int main(int argc, char* argv[]) {
	MQTTClient client;
	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	int rc;
	int ch;

	MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE,
	NULL);
	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;
	conn_opts.username = "admin";
	conn_opts.password = "password";

	MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);

	if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
		printf("Failed to connect, return code %d\n", rc);
		exit(-1);
	}

	MQTTClient_subscribe(client, TOPIC, QOS);
	printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
			"Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
	MQTTClient_subscribe(client, TOPIC, QOS);

	do {
		ch = getchar();
	} while (ch != 'Q' && ch != 'q');

	//e. Disconnect to broker
	MQTTClient_disconnect(client, 10000);

	//f. Release resources
	MQTTClient_destroy(&client);

	return rc;
}
