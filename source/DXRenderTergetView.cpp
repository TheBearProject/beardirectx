#include "DXPCH.h"

uint16 GCountRenderTargetView = 0;

DXRenderTergetView::DXRenderTergetView(bsize w, bsize h, BearGraphics::BearRenderTargetFormat format):m_render_target_texture(0), m_format(format), m_render_target(0)
{
	reisze(w, h);
}

void DXRenderTergetView::reisze(bsize w, bsize h)
{
	if (m_render_target)m_render_target->Release();
	if(m_render_target_texture)BearCore::bear_free(m_render_target_texture);

	m_render_target_texture = BearCore::bear_new<DXTexture2D>( w, h, m_format);

	D3D11_RENDER_TARGET_VIEW_DESC render_terget_view_desc;
	BearCore::bear_fill(render_terget_view_desc);
	render_terget_view_desc.Format = DXFactory::TranslateRenderTargetFromat(m_format);
	render_terget_view_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	R_CHK(Factory->device->CreateRenderTargetView(m_render_target_texture->getTexture(), &render_terget_view_desc, &m_render_target));

	GCountRenderTargetView++;
}


void DXRenderTergetView::clearColor(const BearCore::BearColor & color)
{
	Factory->deviceContext->ClearRenderTargetView(m_render_target, color.getFloat().array);
}

ID3D11ShaderResourceView * DXRenderTergetView::getShaderResource()
{
	return m_render_target_texture->getShaderResource();
}

bptr DXRenderTergetView::getRenderTarget()
{
	return (bptr) m_render_target;
}

void DXRenderTergetView::generateMips()
{
	m_render_target_texture->generateMipmap();
}



DXRenderTergetView::~DXRenderTergetView()
{
	GCountRenderTargetView--;
	m_render_target->Release();
	BearCore::bear_free(m_render_target_texture);
}
