//======================================================================
//　ユーザ型定義
//======================================================================
#ifndef 	__UTYPES_H__
#define 	__UTYPES_H__
#include	<cstdint>
#include	<wtypes.h>
#include	<windef.h>
#include	<winnt.h>

//======================================================================
//　ユーザデータ型
//======================================================================
typedef unsigned char			byte;
typedef unsigned short			u_short;
typedef unsigned int			u_int;		//　※ コンパイラと出力プラットフォームに依存してサイズが変化する点に注意
typedef unsigned long			u_long;
#ifdef		_WIN32
typedef unsigned __int64		u_int64;
typedef __int64 				s_int64;
typedef unsigned __int32		u_int32;
typedef __int32 				s_int32;
typedef unsigned __int16		u_int16;
typedef __int16 				s_int16;
typedef unsigned __int8 		u_int8;
typedef __int8					s_int8;
#else
//　for clang
#include	<cstdint>
typedef uint64_t				u_int64;
typedef int64_t 				s_int64;
typedef uint32_t				u_int32;
typedef int32_t 				s_int32;
typedef uint16_t				u_int16;
typedef int16_t 				s_int16;
typedef uint8_t 				u_int8;
typedef int8_t					s_int8;
#endif	//	_WIN32
typedef unsigned char			u_char;
typedef char					s_char;
typedef const char				c_schar, c_char;
typedef const unsigned char 	c_byte;
typedef const wchar_t			c_wchar;

//======================================================================
//　リテラル文字列（地○の入り口）
//======================================================================
//　実装したい（2017/12/18）
#ifndef 	UNICODE
#else
#endif	//	UNICODE


//======================================================================
//　行列、ベクトル
//======================================================================
#ifdef		_WIN32
//　Windows プラットフォーム

#elif defined(__ANDROID__)
//　Android プラットフォーム

#elif defined(__IPHONE_OS_VERSION_MAX_ALLOWED) || defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
//　iPhoneなんかを実装する気は、更々ない（2017/12/18）
#endif	//



#ifdef		_WIN32
#pragma pack(push,1)
struct	RECT_S
{
	long	x, y;		//　座標
	long	cx, cy; 	//　サイズ
};

//======＜ キーテーブル ＞==============================================
struct	TKeyTable
{
	uint64_t	dwKey;		//　キー（数値）
	c_char *	pValue; 	//　文字列
};
#endif	//	_WIN32

//======＜ 浮動小数点（４成分） ＞======================================
struct	double4
{
	double	x, y, z, w;
};
//======＜ 浮動小数点（３成分） ＞======================================
struct	float3
{
	float	x, y, z;
};
//======＜ 浮動小数点（４成分） ＞======================================
struct	float4
{
	float	x, y, z, w;
};
//======＜ 浮動小数点（２成分） ＞======================================
struct	float2
{
	float	u, v;
};
//======＜ 浮動小数点行列（４成分） ＞==================================
struct	float4x4
{
	float	x0, y0, z0, w0;
	float	x1, y1, z1, w1;
	float	x2, y2, z2, w2;
	float	x3, y3, z3, w3;
};
//======＜ 整数（４成分） ＞============================================
struct	u_int4
{
	uint32_t	r, g, b, a;
};

//======＜ 整数（２成分） ＞============================================
struct	s_int2
{
	int32_t 	u, v;
};

//======＜ 整数（４成分） ＞============================================
struct	s_int4
{
	int32_t 	x, y, z, w;
};

//======＜ 整数（４成分） ＞============================================
struct	u_short4
{
	uint16_t	r, g, b, a;
};
#pragma pack(pop)

//======＜ 整数（４成分） ＞============================================
struct	XMUINT4
{
	uint32_t	x, y, z, w;

	XMUINT4();
	XMUINT4(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
		x = r;
		y = g;
		z = b;
		w = a;
	};
};

//======================================================================
//　インライン関数
//======================================================================
#ifdef		_WIN32
inline LONG
Width(const RECT &  r)
{
	return(r.right - r.left);
}

inline LONG
Height(const RECT &  r)
{
	return(r.bottom - r.top);
}
#endif	//	_WIN32

//======================================================================
//　テンプレート
//======================================================================
#ifdef		_WIN32
#ifndef 	__DEFINE_SAFE_RELEASE__
#define 	__DEFINE_SAFE_RELEASE__
template <class T> void
SafeRelease(T **  p)
{
	if ((p) && (*p)) {
		(*p)->Release();
		(*p) = nullptr;
	}

	return;
}
#endif	//	__DEFINE_SAFE_RELEASE__
#endif	//	_WIN32

#endif	//	__UTYPES_H__
