#pragma once
#include "Libs.h"
#include "InputDevice.h"
using namespace DirectX::SimpleMath;
class CameraController {
	InputDevice* inputDevice;
public:
	float Yaw;
	float Pitch;

	float VelocityMagnitude = 5.0f;
	float MouseSensetivity = 1.0f;

	Camera* camera;
	DirectX::SimpleMath::Vector3 CameraPosition;
	CameraController(InputDevice* inDev, Camera* camera);
	void Update(float deltaTime);

protected:
	void OnMouseMove(const InputDevice::MouseMoveEventArgs& args);

};