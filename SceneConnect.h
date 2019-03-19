#pragma 
#include "Scene.h"
#include "EditText.h"

class SceneConnect : public Scene
{
private:
	ButtonText* mBtnTxtConnect;
	Text* mTxtLogin;
	EditText* editLogin;
	Text* mTxtPass;
	EditText* editPass;
public:
	SceneConnect(SDL_Renderer * pRenderer, int x, int y, int width, int height);
	~SceneConnect();
};

