//==============================================================================
//　フォーマット（uxFormat）
//==============================================================================
#pragma 	once
#include	<cstdint>
#include	<vector>
#include	<DirectXMath.h>

using namespace DirectX;

//======================================================
//　構造体宣言
//======================================================
//　基礎ポリゴン頂点データ
struct	TBVertex
{
	XMFLOAT3	p;		//　頂点座標
	XMFLOAT2	uv; 	//　UV座標
};

//　画素
struct	TColor
{
	uint8_t 	r, g, b, a;
};

//　基礎ポリゴン
struct	TBPolygons
{
	std::vector<TBVertex>	m_pVertices;	//　頂点データ
	std::vector<uint16_t>	m_pIndices; 	//　索引データ

	uint64_t		m_uInputLayoutId;		//　入力レイアウト識別子
	uint32_t		m_uShaderId;			//　シェーダプログラム識別子
	VkIndexType 	m_vkIndexType;			//　索引配列要素サイズ
};

//　頂点バッファ（PMX 用）
struct	TPMXVertex
{
	XMFLOAT4	pos;
	XMFLOAT4	normal;
	XMFLOAT2	uv;
	XMFLOAT2	p1;				//　padding.1
	XMUINT4 	boneno;
	XMFLOAT4	weight;
	uint32_t	weightType; 	//　WEIGHTTYPE
	XMUINT3 	p2;				//　padding.2
	XMFLOAT3	fSDEFC; 		//　SDEFC
	float		p3;				//　padding.3
	XMFLOAT3	fSDEFR0;		//　SDEFR0
	float		p4;				//　padding.4
	XMFLOAT3	fSDEFR1;		//　SDEFR1
	float		fEdgeMag;		//　エッヂ倍率
};
