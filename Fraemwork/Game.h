#pragma warning(disable : 4267)

#define WIN32_LEAN_AND_MEAN
#include "Libs.h"
#include <Windows.h>
#include "DisplayWin32.h"
#include "TriangleComponent.h"
#include "InputDevice.h"
#include "Keys.h"
#include "GameComponent.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

#include <chrono>
#include <thread>


class Game {

	bool isExitRequested;
public:	

	std::vector<GameComponent*> Components;
	DisplayWin32* Display;
	HINSTANCE Instance;
	InputDevice* InDevice;

	Game* tGame;	
	ID3D11Device* Device = nullptr;
	ID3D11Buffer* _vertexBuffer = nullptr;
	ID3D11Buffer* _indexBuffer = nullptr;
	ID3D11Buffer* _constantBuffer = nullptr;	
	ID3D11Debug* _debug = nullptr;

	ID3D11Texture2D* _depthBuffer = nullptr;
	ID3D11DepthStencilView* DepthStencilView = nullptr;

	ID3D11DeviceContext* Context = nullptr;
	IDXGISwapChain* swapChain = nullptr;
	IDXGISwapChain1* swapChain1 = nullptr;
	ID3D11RenderTargetView* RenderView = nullptr;
	ID3DUserDefinedAnnotation* DebugAnnotation = nullptr;

	std::chrono::time_point<std::chrono::steady_clock> PrevTime;
	float TotalTime = 0;
	unsigned int frameCount = 0;

	HRESULT PrepareResources();
	HRESULT InitShaders();
		
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);
	int Draw(HWND hwnd);
	void DestroyResources();
	virtual void Initialize();
	HRESULT CreateBackBuffer();
	virtual void Update(float deltaTime);
	virtual void PostDraw(float deltaTime);
	virtual void Exit();
	virtual void Run();
	virtual void RestoreTargets();
	Game(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow);
};