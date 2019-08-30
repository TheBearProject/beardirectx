#pragma once
#pragma warning(push)
#pragma warning(disable:4324)
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include "d3d12_1.h"
#include "d3dx12.h"
#include <wrl.h>
#include <shellapi.h>
#pragma warning(pop)
#include "BearRenderBase.h"

using Microsoft::WRL::ComPtr;
#define R_CHK(a) BEAR_ASSERT(SUCCEEDED(a))

using namespace BearCore;
#include "DX12RenderInterface.h"
#include "DX12RenderFactory.h"