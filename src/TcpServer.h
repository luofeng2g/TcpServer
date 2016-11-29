/*
 * TcpServer.h
 *
 *  Created on: Nov 24, 2016
 *      Author: nick
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include <set>
#include <list>
#include <sys/select.h>
#include <pthread.h>
#include "command_define.h"

class TcpServer
{
public:
	TcpServer();
	virtual ~TcpServer();
	bool Initialize(unsigned int nPort, unsigned long recvFunc);
	bool SendData(const unsigned char * szBuf, size_t nLen, int socket);
	bool UnInitialize();

private:
	static void * AcceptThread(void * pParam);
	static void * OperatorThread(void * pParam);
	static void * ManageThread(void * pParam);
private:
	int m_server_socket;
	fd_set m_fdReads;
	pthread_mutex_t m_mutex;
	pCallBack m_operaFunc;
	//int m_client_socket[MAX_LISTEN];
	std::set<int> m_client_socket;
	std::list<ServerData> m_data;
	pthread_t m_pidAccept;
	pthread_t m_pidManage;
};

#endif   /* TCPSERVER_H_ */
