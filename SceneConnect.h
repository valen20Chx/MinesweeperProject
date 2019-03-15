#pragma 
#include "Scene.h"
#include "EditText.h"

class SceneConnect : public Scene
{
private:
	ButtonText mBtnTxtConnect;
	EditText editLogin;
	EditText editPass;
public:
	SceneConnect(SDL_Renderer * pRenderer, int x, int y, int width, int height);
	~SceneConnect();
};

