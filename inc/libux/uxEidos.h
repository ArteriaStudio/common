//==============================================================================
//　エイドスファイル（libux）
//==============================================================================
#ifndef 	__UX_EIDOS_H__
#define 	__UX_EIDOS_H__
#include	<vector>
#include	"utypes.h"


//　DirectX Math
#include	<DirectXMath.h>
#include	<DirectXPackedVector.h>

using namespace DirectX;
using namespace DirectX::PackedVector;


//　Vulkanは、glm で行列を作る（必須）
#define 	GLM_FORCE_LEFT_HANDED			//　左手座標系
#define 	GLM_FORCE_DEPTH_ZERO_TO_ONE 	//　深度値を０から１に強制
#define		GLM_ENABLE_EXPERIMENTAL

#include	<glm/glm.hpp>
#include	<glm/vec3.hpp>
#include	<glm/vec4.hpp>
#include	<glm/mat4x4.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<glm/gtx/transform.hpp>


//==============================================================================
//　定数宣言
//==============================================================================
/*
//======＜ プリミティブ識別子 ＞======================================================
enum class	ENbPrimitive : uint32_t
{
	Unknown=0,			//　未定義
	PointList,			//　点リスト
	LineList,			//　線分リスト
	TriangleList,		//　三角形リスト
	LineStrip,			//　線分ストリップ
	TriangleStrip,		//　三角形ストリップ
	TriangleFan,		//　三角形ファン
	Max,
};
*/
//======＜ プリミティブ種類 ＞=======================================================
enum class	ENbOrder : uint32_t
{
	Unknown,		//　未定義
	PointList,		//　点
	LineList,		//　線分
	TriangleList,	//　三角形
	LineStrip,		//　線分ストリップ
	TriangleStrip,	//　三角形ストリップ
	TriangleFan,	//　三角形ファン
	Patch,			//　パッチ
	Max,
};
//======＜ レイアウト識別子 ＞=======================================================
enum class	ENbLayout : int32_t
{
	Unknown=-1, 	//　未定義
	Basic16=0,		//　
	Basic32,		//　
	Basic16_VT, 	//　頂点と画素要素のみ
	TexPoint,		//　テクスチャ付きポイントスプライト
	Space16,		//　座標（u_int16[3]）メッシュ
	ArrLayoutU, 	//　ARR 用入力レイアウト（half4）
	ArrLayoutF, 	//　ARR 用入力レイアウト（float3）
	Basic2, 		//　基本メッシュ
	Basic3, 		//　基本メッシュ
	Basic4, 		//　基本メッシュ
	Basic5, 		//　基本メッシュ
	Max,
};
//======＜ シェーダ種類 ＞==========================================================
enum class	ENbShader : uint32_t
{
	VShader,		//　頂点
	HShader,		//　制御
	DShader,		//　評価
	GShader,		//　幾何
	PShader,		//　画素
	CShader,		//　計算
	Max,
};
const uint32_t	Max_ENbShader = (uint32_t)ENbShader::Max;
//======＜ シェーダ形式 ＞==========================================================
enum class	ENbShaderType : uint32_t
{
	Unknown,	//　不明
	HLSL,		//　HLSL（Direct3D）
	SPIRV,		//　SPIR-V（Vulkan）
	Max,
};
//======＜ 表裏回転形式 ＞==========================================================
enum class	ENbFront
{
	Clockwise=0,		//　時計回り
	CounterClockwise,	//　反時計回り
	Max,
};


//======＜ 加工識別子 ＞============================================================
enum class	ENbPass : uint32_t
{
	Unknown,	//　未定義
	Texts,		//　字形
	Plain,		//　平面
	Deferred,	//　遅延
	Edge,		//　輪郭
	Shade,		//　陰影
	Post,		//　加工
	Merge,		//　合成
	Sample, 	//　中間色
};

//======＜ 支点識別子 ＞============================================================
enum class	ENbJoint : int32_t
{
	ENbJoint_Unknown = -1,
	ENbJoint_Ground,			//　接地点
	ENbJoint_Hips,				//　尻
	ENbJoint_Pelvis,			//　腰（＝重心）

	ENbJoint_Spine_Lower,		//　背骨（下）
	ENbJoint_Spine_Middle,		//　背骨（中）
	ENbJoint_Spine_Upper,		//　背骨（上）

	ENbJoint_Neck_Lower,		//　首（下）
	ENbJoint_Neck_Upper,		//　首（上）

	//　胸
	ENbJoint_L_Breast,			//　左胸
	ENbJoint_R_Breast,			//　右胸

	//　腕
	ENbJoint_L_Shoulder_1,		//　鎖骨（左）
	ENbJoint_R_Shoulder_1,		//　
	ENbJoint_L_Shoulder_2,		//　肩胛骨（左）
	ENbJoint_R_Shoulder_2,		//　
	ENbJoint_L_Elbow,			//　肘（左）
	ENbJoint_R_Elbow,			//　
	ENbJoint_L_Wrist,			//　手首（左）
	ENbJoint_R_Wrist,			//　

	//　指
	ENbJoint_L_Finger_1a,
	ENbJoint_L_Finger_1b,
	ENbJoint_L_Finger_1c,
	ENbJoint_L_Finger_2a,
	ENbJoint_L_Finger_2b,
	ENbJoint_L_Finger_2c,
	ENbJoint_L_Finger_3a,
	ENbJoint_L_Finger_3b,
	ENbJoint_L_Finger_3c,
	ENbJoint_L_Finger_4a,
	ENbJoint_L_Finger_4b,
	ENbJoint_L_Finger_4c,
	ENbJoint_L_Finger_5a,
	ENbJoint_L_Finger_5b,
	ENbJoint_L_Finger_5c,

	ENbJoint_R_Finger_1a,
	ENbJoint_R_Finger_1b,
	ENbJoint_R_Finger_1c,
	ENbJoint_R_Finger_2a,
	ENbJoint_R_Finger_2b,
	ENbJoint_R_Finger_2c,
	ENbJoint_R_Finger_3a,
	ENbJoint_R_Finger_3b,
	ENbJoint_R_Finger_3c,
	ENbJoint_R_Finger_4a,
	ENbJoint_R_Finger_4b,
	ENbJoint_R_Finger_4c,
	ENbJoint_R_Finger_5a,
	ENbJoint_R_Finger_5b,
	ENbJoint_R_Finger_5c,

	//　下半身（脚）
	ENbJoint_Legs,				//　両脚（virtual）
	ENbJoint_L_Thigh,
	ENbJoint_R_Thigh,			//　右太股
	ENbJoint_L_Knee,
	ENbJoint_R_Knee,			//　右膝
	ENbJoint_L_Ankle,
	ENbJoint_R_Ankle,			//　右足首
	ENbJoint_L_Toes,
	ENbJoint_R_Toes,			//　右足先（指の付け根）

	//　フェイシャル
	ENbJoint_Head_Jaw,			//　下顎
	ENbJoint_L_Eyeball, 		//　左眼
	ENbJoint_R_Eyeball, 		//　右眼
	ENbJoint_L_Eye_Corner,		//　左眼隅
	ENbJoint_R_Eye_Corner,		//　右眼隅

	ENbJoint_L_EyeBrow_1,		//　眉内端（左）
	ENbJoint_R_EyeBrow_1,
	ENbJoint_L_EyeBrow_2,		//　眉中端（左）
	ENbJoint_R_EyeBrow_2,
	ENbJoint_L_EyeBrow_3,		//　眉外端（左）
	ENbJoint_R_EyeBrow_3,

	ENbJoint_L_EyeLid_Upper,	//　上瞼（左）
	ENbJoint_R_EyeLid_Upper,	//　上瞼（右）

	ENbJoint_L_EyeLid_Lower_1,	//　下内瞼（左）
	ENbJoint_R_EyeLid_Lower_1,	//　下内瞼（右）
	ENbJoint_L_EyeLid_Lower_2,	//　下中瞼（左）
	ENbJoint_R_EyeLid_Lower_2,	//　下中瞼（右）

	ENbJoint_L_EyeLid_Lower,	//　下中瞼（左）
	ENbJoint_R_EyeLid_Lower,	//　下中瞼（右）

	ENbJoint_L_Lip_Corner,		//　唇左端
	ENbJoint_R_Lip_Corner,		//　唇右端

	Max_ENbJoint,
};

//======＜ リソース種類 ＞==========================================================
enum class	ENbResType : uint32_t
{
	ENbResType_Unknown, 	//　不明
	Texture, 	//　テクスチャ
	ENbResType_Light,		//　光源
	Max_ENbResType,
};

//======＜ テクスチャ種類 ＞=========================================================
enum class	ENbTexType : int32_t
{
	//　ジオメトリ毎
	Unknown=-1,	//　未定義
	Normal=0,	//　法線マップテクスチャ
	Diffuse, 	//　拡散反射色テクスチャ
	Specura, 	//　鏡面反射色テクスチャ
	Palette, 	//　カラーセットテクスチャ
	Mask,		//　マスク色テクスチャ
	Displace,	//　置換テクスチャ
	Light,		//　ライトマップ
	Mirror,		//　環境マップ
/*
	//　シェーダ毎
	Color,		//　描画バッファ（又は、画像テクスチャ）
	Depth,		//　深度バッファ
	Shade0,		//　影マップ（前）
	Shade1,		//　影マップ（中）
	Shade2,		//　影マップ（奥）
				//　予約
	Other,		//　不明
	Unknown, 	//　未定義
*/
	Max,
};
const int32_t	Max_ENbTexType = (int32_t)ENbTexType::Max;
//const int	Max_ENbTexType_Geometry = ENbTexType_Color;	//　ジオメトリ用リソース数
const int32_t	Max_ENbTexType_Geometry = (int32_t)ENbTexType::Max; 	//　ジオメトリ用リソース数
//======＜ 入力スロット種類 ＞=======================================================
enum class	ENbTexSlot : int32_t
{
	Color = Max_ENbTexType,
	Depth,		//　
	Shade0, 	//　
	Shade1, 	//　
	Shade2, 	//　
	SpaceC, 	//　空間：画素
	SpaceD, 	//　空間：深度
	PlainC, 	//　平面：画素
	PlainD, 	//　平面：深度
	GlyphC, 	//　字形：画素
	GlyphD, 	//　字形：深度
	Max,
};
const int32_t	Max_ENbTexSlot = (int32_t)ENbTexSlot::Max;

//======＜ 入力アタッチメント種類 ＞===================================================
enum class	ENbAttachment : uint32_t
{
	ENbAttachment_Space = Max_ENbTexType,		//　入力アタッチメント：画素＋深度（空間レイヤ）
	ENbAttachment_Plain,						//　入力アタッチメント：画素＋深度（平面レイヤ）
	ENbAttachment_Glyph,						//　入力アタッチメント：画素＋深度（字形レイヤ）
	Max_ENbAttachment,
};

//======＜ リソース形式 ＞==========================================================
enum class	ENbTexKind : uint32_t
{
	Unknown, 				//　未定義
	R8G8B8A8_UINT,			//　RGBA 8bit 符号なし整数（0～255）
	R8G8B8A8_UNORM, 		//　RGBA 8bit 符号なし浮動小数点（0.0～1.0）
	B8G8R8A8_UNORM, 		//　BGRA 8bit 符号なし浮動小数点（0.0～1.0）
	BC1_UNORM,				//　BC1
	BC3_UNORM,				//　BC3
	B8G8R8A8_UNORM_SRGB,	//　RGBA 8bit 符号なし浮動小数点（0.0～1.0）SRGB
	R32_FLOAT,				//　R 32bit 浮動小数点
	R32_TYPELESS,			//　R 32bit データ型未指定（深度バッファ用）
	R16G16B16A16_UNORM, 	//　RGBA 16bit 符号なし浮動小数点（0.0～1.0）
	BC7_UNORM,				//　BC7
	Max,
};
const uint32_t	Max_ENbTexKind = (uint32_t)ENbTexKind::Max;

//======＜ 描画パイプライン識別子 ＞==================================================
enum class	ENbLinear : uint32_t
{
	Unknown=UINT32_MAX, 	//　不明
	Default=0,				//　既定
	AlphaBlend, 			//　αブレンド
	AlphaBlend_INVSRCA, 	//　
	Wire,					//　ワイヤフレーム
	Caret,					//　キャレット
	Max,
};
const uint32_t	Max_ENbLinear = (uint32_t)ENbLinear::Max;

//==============================================================================
//　構造体宣言
//==============================================================================
#pragma pack(push,1)
//======＜ ジオメトリレコード（ArtGeometry） ＞========================================
struct	TArtGeometry
{
	uint32_t	uHash;			//　ハッシュ値
	uint32_t	nObjects;		//　メッシュ数（単位：要素数）
	uint32_t	nJoints;		//　支点数（単位：要素数）
	uint32_t	nMotions;		//　運動数（単位：要素数）
	uint32_t	nPoints;		//　付帯座標数（単位：要素数）
	uint32_t	uFiller[3]; 	//　フィラー
};

//======＜ メッシュプロパティ ＞========================================
struct	TArtPolygon
{
	ENbOrder		eOrder; 		//　プリミティブ（ENbOrder）
	ENbLayout		eLayout;		//　レイアウト識別子（ENbLayout）
	uint32_t		nVertexes;		//　頂点配列要素数
	uint32_t		nIndexes;		//　索引配列要素数
	uint32_t		nResources; 	//　リソース要素数（テクスチャ）
	uint16_t		uVertex;		//　頂点配列要素サイズ（単位：バイト）
	uint16_t		uTexture;		//　画素配列要素サイズ（単位：バイト）
	uint16_t		uColor; 		//　色素配列要素サイズ（単位：バイト）
	uint16_t		uIndex; 		//　索引配列要素サイズ（単位：バイト）
	uint32_t		uShader;		//　シェーダ識別子
	uint32_t		uBlend; 		//　パイプライン識別子
//	uint32_t		nDescriptors;	//　入力記述子集合数（4：入力アタッチメントなし、5：入力アタッチメントあり）
	uint32_t		uState; 		//　初期表示状態
	uint32_t		uFiller[1]; 	//　フィラー
};

#ifdef		USE_DIRECTMATH
//======＜ 頂点要素（16bit float） ＞===================================
struct	TNbVertex16
{
	XMHALF4 	p;		//　頂点座標（POSITION：オブジェクト座標系）
	XMHALF4 	w;		//　頂点ブレンド重み値（BLENDWEIGHT）
	XMHALF4 	i;		//　頂点ブレンド重み番号（BLENDINDICES）
	XMHALF4 	n;		//　法線ベクトル（NORMAL：オブジェクト座標系？）
	XMHALF4 	t;		//　接線ベクトル（TANGENT：オブジェクト座標系）
	XMHALF4 	b;		//　従法線ベクトル（BINORMAL：オブジェクト座標系？）
};
#else
//======＜ 頂点要素（16bit float） ＞===================================
struct	TNbVertex16
{
	uint64_t	p;		//　頂点座標（POSITION：オブジェクト座標系）
	uint64_t	w;		//　頂点ブレンド重み値（BLENDWEIGHT）
	uint64_t	i;		//　頂点ブレンド重み番号（BLENDINDICES）
	uint64_t	n;		//　法線ベクトル（NORMAL：オブジェクト座標系？）
	uint64_t	t;		//　接線ベクトル（TANGENT：オブジェクト座標系）
	uint64_t	b;		//　従法線ベクトル（BINORMAL：オブジェクト座標系？）
};
#endif	//	USE_DIRECT3D
typedef std::vector<TNbVertex16>	VNbVertex16;
typedef VNbVertex16::iterator		INbVertex16;

//======＜ 頂点要素（32bit float） ＞===================================
struct	TNbVertex32
{
	float4		p;		//　頂点座標（POSITION：オブジェクト座標系）
	float4		w;		//　頂点ブレンド重み値（BLENDWEIGHT）
	float4		i;		//　頂点ブレンド重み番号（BLENDINDICES）
	float4		n;		//　法線ベクトル（NORMAL：オブジェクト座標系？）
	float4		t;		//　接線ベクトル（TANGENT：オブジェクト座標系）
	float4		b;		//　従法線ベクトル（BINORMAL：オブジェクト座標系？）
};
typedef std::vector<TNbVertex32>	VNbVertex32;
typedef VNbVertex32::iterator		INbVertex32;

#ifdef		USE_DIRECTMATH
//======＜ 画素要素（16bit float） ＞===================================
struct	TNbTexels16
{
	XMHALF4 	c;			//　基本色成分（COLOR0）
	XMHALF4 	d;			//　拡散成分（COLOR1）
	XMHALF4 	s;			//　鏡面成分（COLOR2）
	XMHALF2 	uv; 		//　テクセル座標（TEXCOORD）
};
#else
struct	TNbTexels16
{
	uint64_t 	c;			//　基本色成分（COLOR0）
	uint64_t 	d;			//　拡散成分（COLOR1）
	uint64_t 	s;			//　鏡面成分（COLOR2）
	uint32_t 	uv; 		//　テクセル座標（TEXCOORD）
};
#endif	//	USE_DIRECTMATH
typedef std::vector<TNbTexels16>	VNbTexels16;
typedef VNbTexels16::iterator		INbTexels16;

//======＜ 画素要素（32bit float） ＞===================================
struct	TNbTexels32
{
	float4		c;			//　基本色成分（COLOR0）
	float4		d;			//　拡散成分（COLOR1）
	float4		s;			//　鏡面成分（COLOR2）
	float2		uv; 		//　テクセル座標（TEXCOORD）
	float2		filler; 	//（アライメント整列）
};
typedef std::vector<TNbTexels32>	VNbTexels32;
typedef VNbTexels32::iterator		INbTexels32;

//======＜ 色素要素（16bit float） ＞===================================
struct	TNbColors16
{
	XMHALF4		fH[2];		//　ホバ状態色（[0]：非ホバ：COLOR3）
	XMHALF4		fS[2];		//　仕掛状態色（[0]：非仕掛：COLOR4）
	XMHALF4		fF[2];		//　入力状態色（[0]：非入力：COLOR5）
	XMHALF4		fD[2];		//　受付状態色（[0]：受付中：COLOR6）
	XMHALF4		fM[2];		//　注目状態色（[0]：非注目：COLOR7）
	XMHALF4		fC[2];		//　選択状態色（[0]：非選択：COLOR8）
};
typedef std::vector<TNbColors16>	VNbColors16;
typedef VNbColors16::iterator		INbColors16;

//======＜ 色素要素（32bit float） ＞===================================
struct	TNbColors32
{
	float4		fH[2];		//　ホバ状態色（[0]：非ホバ：COLOR3）
	float4		fS[2];		//　仕掛状態色（[0]：非仕掛：COLOR4）
	float4		fF[2];		//　入力状態色（[0]：非入力：COLOR5）
	float4		fD[2];		//　受付状態色（[0]：受付中：COLOR6）
	float4		fM[2];		//　注目状態色（[0]：非注目：COLOR7）
	float4		fC[2];		//　選択状態色（[0]：非選択：COLOR8）
};
typedef std::vector<TNbColors32>	VNbColors32;
typedef VNbColors32::iterator		INbColors32;

//======＜ 索引要素（16bit integer） ＞=================================
struct	TNbIndexs16
{
	uint16_t	p;		//　頂点番号（u_int16）
};
typedef std::vector<TNbIndexs16>	VNbIndexs16;
typedef VNbIndexs16::iterator		INbIndexs16;

//======＜ 索引要素（32bit integer） ＞=================================
struct	TNbIndexs32
{
	uint32_t	p;		//　頂点番号（u_int32）
};
typedef std::vector<TNbIndexs32>	VNbIndexs32;
typedef VNbIndexs32::iterator		INbIndexs32;

//======＜ 参照配列レコード（vide） ＞==================================
struct	TNbSource32
{
	ENbTexType	uType;		//　テクスチャ種類（種類＝スロット）
	uint32_t	uHash;		//　リソース識別子（ハッシュ値）
};
typedef std::vector<TNbSource32>	VNbSource32;
typedef VNbSource32::iterator		INbSource32;
struct	TNbSource16
{
	ENbTexType	uType;		//　テクスチャ種類（種類＝スロット）
	uint32_t	uHash;		//　リソース識別子（ハッシュ値）
};
typedef std::vector<TNbSource16>	VNbSource16;
typedef VNbSource16::iterator		INbSource16;

#ifdef		USE_DIRECT3D
//======＜ 支点配列レコード ＞==========================================
struct	TNbJoints
{
	uint32_t	uJoint; 		//　支点識別子
	uint32_t	uParent;		//　親支点要素番号
	uint32_t	uFiller[3]; 	//　フィラー
	XMFLOAT4	p;				//　支点座標
	XMFLOAT4	n;				//　法線ベクトル
	XMFLOAT4	t;				//　接線ベクトル
	XMFLOAT4	b;				//　従法線ベクトル
};
#else
//======＜ 支点配列レコード ＞==========================================
struct	TNbJoints
{
	uint32_t	uJoint; 		//　自支点識別子
	uint32_t	uParent;		//　親支点識別子
//	uint32_t	uChild; 		//　子支点要素番号
	uint32_t	uFiller[3]; 	//　フィラー
	float4		p;				//　支点座標
	float4		n;				//　法線ベクトル
	float4		t;				//　接線ベクトル
	float4		b;				//　従法線ベクトル
};
#endif	//	USE_DIRECT3D

//======＜ 運動配列レコード ＞==========================================
struct	TNbMotions
{
	uint32_t	uMotion;		//　運動識別子
};

#ifdef		USE_DIRECT3D
//======＜ 付帯座標配列レコード ＞======================================
struct	TNbPoints
{
	uint32_t	uPoint; 		//　付帯座標識別子
	uint32_t	uFiller;		//　フィラー
	XMFLOAT4	p;				//　付帯座標
};
#else
//======＜ 付帯座標配列レコード ＞======================================
struct	TNbPoints
{
	uint32_t	uPoint; 		//　付帯座標識別子
	uint32_t	uFiller;		//　フィラー
	float4		p;				//　付帯座標
};
#endif	//	USE_DIRECT3D

//======＜ マテリアルプロパティ（ArtMaterial） ＞=======================
struct	TArtMaterial
{
	uint32_t	uHash;			//　ハッシュ値
	uint32_t	nResources; 	//　リソース数（単位：要素数）
	uint64_t	uFiller;		//　フィラー
};
//======＜ リソースプロパティ ＞========================================
struct	TNbResource
{
	ENbResType	rType;			//　リソース種類
	uint32_t	uHash;			//　リソース識別子（ハッシュ値）
	uint32_t	nSize;			//　リソースサイズ［単位：バイト］
//	ENbTexType	uType;			//　テクスチャ種類（種類＝スロット）
	uint32_t	uType;			//　テクスチャ種類（種類＝スロット）
	ENbTexKind	uKind;			//　テクスチャ形式（＝DXGI_FORMAT）
	uint32_t	nOrder; 		//　テクスチャ次元
	uint32_t	uLine;			//　テクスチャ行幅（scanline、単位：バイト）
	uint32_t	uWidth; 		//　テクスチャ幅
	uint32_t	uHeight;		//　テクスチャ高
	uint32_t	uDepth; 		//　テクスチャ深度
	uint32_t	uArray; 		//　テクスチャ配列要素数
	uint32_t	uFiller;		//　フィラー
};

//======＜ モデルプロパティ ＞==========================================
struct	TArtModels
{
	uint32_t	uHash;			//　ハッシュ値
	uint32_t	nModels;		//　モデル数（単位：要素数）
	uint64_t	uFiller;		//　フィラー
};

//======＜ モデルデータ ＞==============================================
struct	TArtModel
{
	char		cName[16];		//　モデル識別名
	uint32_t	uHash;			//　モデル識別子（CRC32ハッシュ値）
	uint32_t	uCksum; 		//　チェックサム
	uint64_t	uFiller;		//　フィラー
};


//======＜ 行列（４成分） ＞============================================
//　glm(GLMath)ライブラリを基本とした実装とするのが好ましい（2018/12/11）
//#define		USE_GLMATH
#ifdef		USE_DIRECTMATH
typedef DirectX::XMFLOAT4		vector4;
//typedef DirectX::XMMATRIX 	matrix;
typedef DirectX::XMFLOAT4X4 	matrix;
#endif	//	USE_DIRECTMATH
#ifdef		USE_GLMATH
//　Vulkan HAL
typedef glm::vec4		vector4;	//　4成分32bit浮動小数点
//typedef glm::vec3		Float3; 	//　3成分32bit浮動小数点
//typedef glm::vec2		Float2; 	//　2成分32bit浮動小数点
typedef glm::mat4		matrix; 	//　4行4列32bit浮動小数点（4x4行列）
#endif	//	USE_GLMATH

//======＜ （TIxTantum） ＞=========================
struct	TIxTantum
{
	float4		Duration;		//　経過時間（x：経過時間［フレーム］）
	float4		AlphaRate;		//　α値レート
	float4		PI; 			//　円周率

	TIxTantum();
};
//======＜ ビュー変換行列定義レコード ＞================================
//　ワールド座標系からカメラ空間を切り取る行列
//　処理契機が近いので、同時に光源処理に用いる光源座標を含めている
struct	TIxCamera
{
	float4x4	m_mEyeView; 	//　ビュー変換行列（視点観点）
	float4		m_vEye; 		//　視点座標（*ビュー*座標系、xyz：座標）
	float4		m_vFocus;		//　注視点座標（*ビュー*座標系、xyz：座標）

	TIxCamera();

//void	LookAt(glm::vec4  eye, glm::vec4  focus, glm::vec4  axis);
#ifdef		USE_DIRECTMATH
	void	LookAt(XMVECTOR  eye, XMVECTOR  focus, XMVECTOR  axis);
#endif	//	USE_DIRECTMATH
#ifdef		USE_GLMATH
	void	LookAt(glm::vec4  eye, glm::vec4  focus, glm::vec4  axis);
#endif	//	USE_GLMATH

	void	SetMatrix(glm::mat4  m);
};
//======＜ 射影変換行列定義レコード ＞==================================
//　カメラ視界、被写界深度といった射影に関する操作に使用する行列
//　視界に関わる行列であるので、殆ど初期値から変化させない
const size_t	TIxShadows = 3; 	//　シャドウマップ数
struct	TIxFinder
{
	float4x4	Camera; 				//　射影変換行列（視点観点）
	float4x4	Shadows[TIxShadows];	//　射影変換行列（光源観点）
	float4		iLayer; 				//　射影変換行列（光源観点）の使用する要素番号（.r：要素番号）
	float4x4	Window; 				//　射影変換行列（視点観点）
	float4x4	TexUV;					//　画像変換行列（？観点）
#if 0
	TIxFinder();

	void	Projection(float  fFoV, float  fAspect, float  fNearZ, float  fFarZ);
#endif
};
//======＜ 光源パラメータレコード ＞====================================
struct	TIxLumina
{
	float4x4	LightViews[3];	//　光源座標行列（光源観点）
	float4		Lights[3];		//　光源座標（*ビュー*座標系、xyz：座標）

	float4		Ambient;		//　環境特性（xyz:RGB）
	float4		Diffuse;		//　拡散特性（xyzw：拡散反射色）
	float4		Specular;		//　鏡面特性（xyzw：鏡面反射色）
	float4		Lighter;		//　光源特性（x：減衰距離、z：フォン係数、w：輝度）
	float4		Intensity;		//　輝度特性（x：拡散反射、y：鏡面反射、z：陰影深度、w：反射強度）

	TIxLumina();

#ifdef		USE_DIRECTMATH
	void	LookAt(XMVECTOR  light, XMVECTOR  focus, XMVECTOR  axis);
	void	LookAtPolar(XMVECTOR  light, XMVECTOR  focus, XMVECTOR  axis);
	void	LookAt1(XMVECTOR  light, XMVECTOR  focus, XMVECTOR  axis);
#endif	//	USE_DIRECTMATH
#ifdef		USE_GLMATH
	void	LookAt(glm::vec4  light, glm::vec4  focus, glm::vec4  axis);
#endif	//	USE_GLMATH
	void	SetMatrix(glm::mat4  m);

	void	SetAmbient(float4  ambient);
	void	SetDiffuse(float4  diffuse, float  intensity);
	void	SetSpecular(float4  specular, float  intensity, float  exponent);
	void	SetPosition(uint32_t  i, float4  fPosition);
	void	SetPosition(uint32_t  i, glm::vec3  vPosition);
	void	SetPosition(uint32_t  i, glm::vec4  vPosition);

	void	AddDiffuse(float4  diffuse, float  fIntensity);
	void	AddSpecular(float4  specular, float  fIntensity, float  fExponent);
	void	AddShadowDepth(float  fShadowDepth);

	void	GetDiffuse(float4 &  diffuse, float &  intensity);
	void	GetSpecular(float4 &  specular, float &  intensity, float &  fExponent);
	void	GetIntensity(float4 &  intensity);
	void	GetShadowDepth(float &  fShadowDepth);
};
//======＜ ワールド変換行列定義レコード（ジオメトリ単位） ＞============
//　モデル座標系からワールド座標系に変換する行列
struct	TIxStatum
{
//	matrix		World;			//　ワールド変換行列
	float4x4	World;			//　ワールド変換行列
	u_int4		ViewState;		//　ジオメトリ状態（r：ジオメトリ状態、gba：未使用）

	TIxStatum();

	void	SetTranslation_DX(float  fOffsetX, float  fOffsetY, float  fOffsetZ);
	void	SetTranslation_VK(float  fOffsetX, float  fOffsetY, float  fOffsetZ);
	void	SetRotate_DX(float  fDeltaP, float  fDeltaY, float  fDeltaR);
	void	SetRotate_VK(float  fDeltaP, float  fDeltaY, float  fDeltaR);
};
//======＜ 支点座標変換行列（ジオメトリ単位） ＞========================
struct	TIxRigide
{
//	matrix		Joint[64];		//　支点座標変換行列
//	matrix		Joint[512]; 	//　支点座標変換行列
	float4x4	Joint[265]; 	//　支点座標変換行列

	TIxRigide();

	void	SetTranslation_DX(uint32_t  uJoint, float  fOffsetX, float  fOffsetY, float  fOffsetZ);
	void	SetTranslation_VK(uint32_t  uJoint, float  fOffsetX, float  fOffsetY, float  fOffsetZ);
	void	SetRotate_DX(uint32_t  uJoint, float  fDeltaP, float  fDeltaY, float  fDeltaR);
	void	SetRotate_VK(uint32_t  uJoint, float  fDeltaP, float  fDeltaY, float  fDeltaR);
};
//======＜ 変更情報変換行列（メッシュ単位） ＞==========================
struct	TIxMutare
{
	float4		Hue;			//　色相
	u_int4		ItemState;		//　項目状態（r：項目状態、gba：未使用）

	TIxMutare();
};
#pragma pack(pop)

//==============================================================================
//　クラス宣言
//==============================================================================

#endif	//	__UX_EIDOS_H__
