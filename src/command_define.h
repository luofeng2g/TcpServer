/*
 * command_define.h
 *
 *  Created on: Nov 24, 2016
 *      Author: nick
 */

#ifndef COMMAND_DEFINE_H_
#define COMMAND_DEFINE_H_

#include <stddef.h>

const int MAX_LISTEN = 3000;
const int SERVER_LISTEN_PORT = 8000;
const int MAX_DATA_LEN = 4096;

typedef struct
{
	unsigned char buf[MAX_DATA_LEN];
	size_t nLen;
	int socket;
}ServerData, *pServerData;

typedef void (*pCallBack)(const char * szBuf, size_t nLen, int socket);

#endif  /* COMMAND_DEFINE_H_ */
