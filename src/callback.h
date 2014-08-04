/*
 * callback.h
 *
 *  Created on: Aug 4, 2014
 *      Author: hafizur
 */

#ifndef CALLBACK_H_
#define CALLBACK_H_
#include "MQTTClient.h"

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt) {
	printf("Message with token value %d delivery confirmed\n", dt);

	deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen,
		MQTTClient_message *message) {
	int i;
	char* payloadptr;
	printf("Message arrived\n");
	printf(" topic: %s\n", topicName);
	printf(" message: ");
	payloadptr = message->payload;
	for (i = 0; i < message->payloadlen; i++) {
		putchar(*payloadptr++);
	}
	putchar('\n');
	MQTTClient_freeMessage(&message);

	return 1;
}

void connlost(void *context, char *cause) {
	printf("\nConnection lost\n");
	printf(" cause: %s\n", cause);
}

#endif /* CALLBACK_H_ */
