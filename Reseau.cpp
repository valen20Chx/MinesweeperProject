#include "Reseau.h"

Reseau::Reseau(std::string serverHostName, Uint16 port)
{
	this->serverHostName = serverHostName;
	this->port = port;
	this->state = RESEAU_DECO;
	this->socket = NULL;
	if (SDLNet_ResolveHost(&this->ip, this->serverHostName.c_str(), this->port) == -1)
	{
		std::cerr << "ERROR : SDLNet_ResolveHost() : " << SDLNet_GetError() << std::endl;
	}
	this->socket = SDLNet_TCP_Open(&this->ip);
	if (!this->socket)
	{
		std::cerr << "ERROR : SDLNet_TCP_Open() : " << SDLNet_GetError() << std::endl;
	}
}

int Reseau::connect()
{
	this->socket = SDLNet_TCP_Open(&this->ip);
	if (!this->socket)
	{
		std::cerr << "ERROR : SDLNet_TCP_Open() : " << SDLNet_GetError() << std::endl;
		return RESEAU_FAILURE;
	}
	this->state = RESEAU_CO;
	return RESEAU_SUCCESS;
}

int Reseau::send(std::string msg)
{
	int len, result;

	len = strlen(msg.c_str()) + 1;

	result = SDLNet_TCP_Send(this->socket, msg.c_str(), len);

	if (result < len)
	{
		std::cerr << "ERROR : SDLNet_TCP_Send() : " << SDLNet_GetError() << std::endl;
		SDLNet_TCP_Close(this->socket);
		this->state = RESEAU_DECO;
		return RESEAU_FAILURE;
	}

	return RESEAU_SUCCESS;
}

const char* Reseau::recv()
{
	int result;
	char msg[RESEAU_TCP_DATA_MAXLEN];
	result = SDLNet_TCP_Recv(this->socket, msg, RESEAU_TCP_DATA_MAXLEN);
	if (result <= 0)
	{
		std::cerr << "ERROR : SDLNet_TCP_Recv() : " << SDLNet_GetError() << std::endl;
		SDLNet_TCP_Close(this->socket);
		this->state = RESEAU_DECO;
		return "";
	}
	return msg;
}

Reseau::~Reseau()
{
	SDLNet_TCP_Close(this->socket);
}

int Reseau::get_state()
{
	return this->state;
}

void Reseau::set_state(int state)
{
	this->state = state;
}
