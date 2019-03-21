#pragma once

#include <SDL_net.h>
#include <iostream>
#include <string>

#define RESEAU_TCP_DATA_MAXLEN 1024

enum Reseau_Return {
	RESEAU_SUCCESS,
	RESEAU_FAILURE
};

enum Reseau_State {
	RESEAU_CO,
	RESEAU_DECO
};

class Reseau
{
private:
	IPaddress ip;
	TCPsocket socket;
	Uint16 port;
	int state;
	std::string serverHostName;
public:
	Reseau(std::string serverHostName, Uint16 port);
	int connect();
	int send(std::string msg);
	const char* recv();
	~Reseau();
	int get_state();
	void set_state(int state);
};