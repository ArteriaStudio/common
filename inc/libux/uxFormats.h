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

//　共通頂点バッファ
struct	TPMXVertex
{
	XMFLOAT4	pos;
	XMFLOAT4	normal;
	XMFLOAT2	uv;
	XMUINT4 	boneno;
	XMFLOAT4	weight;
	uint32_t	weightType; 	//　WEIGHTTYPE
	XMFLOAT3	fSDEFC; 		//　SDEFC
	XMFLOAT3	fSDEFR0;		//　SDEFR0
	XMFLOAT3	fSDEFR1;		//　SDEFR1
};
