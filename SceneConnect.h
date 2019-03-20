#pragma 
#include "Scene.h"
#include "EditText.h"

class SceneConnect : public Scene
{
private:
	ButtonText* mBtnTxtConnect;
	Text* mTxtLogin;
	EditText* editLogin;
public:
	SceneConnect(SDL_Renderer * pRenderer, int x, int y, int width, int height);
	~SceneConnect();
	std::string get_login();
	void draw();
	void input(SDL_Event eventListener);
};

