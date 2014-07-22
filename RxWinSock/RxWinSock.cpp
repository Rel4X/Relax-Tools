#include		<string>
#include		"RxWinSock.h"

/* Version 1.0 */

int				RxWinSock::sockCount = 0;

RxWinSock::RxWinSock(void) :
p_connected(false), p_socket(-1)
{
	memset(&this->p_infos, 0, sizeof(this->p_infos));
}

RxWinSock::~RxWinSock(void)
{
	if (this->p_connected == true)
		this->Reset();
}

void			RxWinSock::Disconnect()
{
	this->Reset();
}

void			RxWinSock::Reset()
{
	if (this->p_connected == true)
		closesocket(this->p_socket);
	this->p_connected = false;
	this->p_socket = -1;
	memset(&this->p_infos, 0, sizeof(this->p_infos));
	if (RxWinSock::sockCount == 1)
	{
		RxWinSock::sockCount = 0;
		WSACleanup();
	}
	else if (RxWinSock::sockCount > 1)
		RxWinSock::sockCount -= 1;
}

int				RxWinSock::WinInit()
{
	WSADATA		WSAData;

	if (RxWinSock::sockCount == 0)
	{
		if (WSAStartup(MAKEWORD(2, 0), &WSAData) == 0)
		{
			RxWinSock::sockCount = 1;
			return (0);
		}
		return (-1);
	}
	RxWinSock::sockCount += 1;
	return (0);
}

bool			RxWinSock::ServerInit(const std::string& port)
{
	if (this->p_connected == false)
	{
		this->WinInit();
		this->p_infos.sin_family = AF_INET;
		this->p_infos.sin_port = htons(atoi(port.c_str()));
		this->p_infos.sin_addr.s_addr = INADDR_ANY;
		this->p_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (this->p_socket == -1
			|| (bind(this->p_socket, (const sockaddr*)&this->p_infos, sizeof(struct sockaddr_in)) == -1)
			|| (listen(this->p_socket, 42) == -1))
		{
			this->Reset();
			return (false);
		}
		this->p_connected = true;
		return (true);
	}
	return (false);
}

RxWinSock*		RxWinSock::Accept()
{
	RxWinSock*	newSocket;
	int			size;

	if (this->p_connected == true)
	{
		newSocket = new RxWinSock();
		size = sizeof(newSocket->p_infos);
		newSocket->p_socket = accept(this->p_socket, (struct sockaddr*)&newSocket->p_infos, &size);
		if (newSocket > 0)
		{
			newSocket->p_connected = true;
			newSocket->WinInit();
			return (newSocket);
		}
	}
	this->Reset();
	return (0);
}

bool			RxWinSock::Connect(const std::string& ip, const std::string& port)
{
	if (this->p_connected == false)
	{
		this->WinInit();
		this->p_infos.sin_family = AF_INET;
		this->p_infos.sin_port = htons(atoi(port.c_str()));
		this->p_infos.sin_addr.s_addr = inet_addr(ip.c_str());
		this->p_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (connect(this->p_socket, (const sockaddr*)&this->p_infos, sizeof(struct sockaddr_in)) == 0)
		{
			this->p_connected = true;
			return (true);
		}
		this->Reset();
		return (false);
	}
	return (false);
}

int				RxWinSock::Receive(char* buffer, unsigned int size)
{
	int			received;

	if (this->p_connected == true && buffer != 0 && size > 0)
	{
		received = recv(this->p_socket, buffer, size, 0);
		return (received);
	}
	return (-1);
}

int				RxWinSock::Send(const char* buffer, unsigned int size)
{
	int			sent;

	if (this->p_connected == true && buffer != 0 && size > 0)
	{
		sent = send(this->p_socket, buffer, size, 0);
		if (sent == SOCKET_ERROR)
			return (-1);
		return (sent);
	}
	return (-2);
}
