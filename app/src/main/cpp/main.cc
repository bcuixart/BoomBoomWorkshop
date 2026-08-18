#include "raymob.h"

#include "GameManager.hh"
#include "LoadingScreen.hh"

int main()
{
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0, 0, "Boom Boom Workshop");
    SetExitKey(KEY_NULL);

    InitAudioDevice();
    SetTargetFPS(30);

	LoadingScreen* loadingScreen = new LoadingScreen();
	loadingScreen->DrawLoadingScreen(GetScreenWidth(), GetScreenHeight());

    GameManager* gameManager = new GameManager();

	delete loadingScreen;

    float deltaTime = 0;
    while (!WindowShouldClose() && !gameManager->PlayerExited())
    {
        deltaTime = GetFrameTime();

        gameManager->Update(deltaTime);
        gameManager->Render(deltaTime);
    }

    delete gameManager;

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
