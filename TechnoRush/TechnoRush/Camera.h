#pragma once
#include <DirectXMath.h>
#include <d3d11.h>

class GameEntity;
class Camera
{
public:
	Camera();
	~Camera(void);

	void Resize(float aspectRatio);
	void RenderScene(GameEntity** entities, int numEntities, ID3D11RenderTargetView* renderTargetView, ID3D11DepthStencilView* depthStencilView, ID3D11DeviceContext* deviceContext, DirectX::XMFLOAT4X4& viewData, DirectX::XMFLOAT4X4& projectionData);

	void SetViewParameters(DirectX::XMFLOAT3 position, DirectX::XMFLOAT3 lookAt, DirectX::XMFLOAT3 up);

	DirectX::XMFLOAT4X4 view();
	DirectX::XMFLOAT4X4 projection();
	unsigned int cullingMask();
	void cullingMask(int newMask);
	DirectX::XMFLOAT4 position();
	void position(DirectX::XMFLOAT4 newPosition);
	bool orthographic();
	void orthographic(bool isOrthographic);
	bool clearDepth();
	void clearDepth(bool isClearDepth);
	bool clearStencil();
	void clearStencil(bool isClearStencil);
	bool clearRenderTarget();
	void clearRenderTarget(bool isClearRenderTarget);

private:
	void Update();

	DirectX::XMFLOAT4X4 _view;
	DirectX::XMFLOAT4X4 _projection;

	DirectX::XMFLOAT4 _position;
	DirectX::XMFLOAT4 _lookAt;
	DirectX::XMFLOAT4 _up;

	float _clearColor[4];
	float _fieldOfView;
	float _near, _far;
	float _width;
	bool _orthographic;
	bool _clearDepth;
	bool _clearStencil;
	bool _clearRenderTarget;

	unsigned int _cullingMask;
};

