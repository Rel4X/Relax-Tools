#pragma once

/* Version 1.0 */

#include		<string>
#include		<Windows.h>

#pragma			comment(lib, "ws2_32.lib")

class			RxWinSock
{
private:
	static int				sockCount;

protected:
	int						p_socket;
	struct sockaddr_in		p_infos;
	bool					p_connected;

public:
	RxWinSock(void);
	~RxWinSock(void);

public:
	const struct sockaddr_in*	GetInfos() const		{ return (&this->p_infos); }

public:
	int					GetSocket() const		{ return (this->p_socket); }
	bool				IsConnected() const		{ return (this->p_connected); }
	const char*			GetIpAddres() const		{ return (inet_ntoa(this->p_infos.sin_addr)); }

public:
	void				Disconnect();
	bool				ServerInit(const std::string&);
	RxWinSock*			Accept();
	bool				Connect(const std::string&, const std::string&);
	int					Receive(char*, unsigned int);
	int					Send(const char*, unsigned int);

protected:
	void				Reset();
	int					WinInit();
};
