#pragma once
class DX12SamplerState :public BearRHI::BearRHISampler
{
public:
	DX12SamplerState(const BearSamplerDescription& Description);
	virtual ~DX12SamplerState();
	D3D12_SAMPLER_DESC desc;
};