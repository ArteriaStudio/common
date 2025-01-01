#ifndef 	__UCONSTANTS_H__
#define 	__UCONSTANTS_H__

//======================================================
//　ユーザ定数
//======================================================
#ifndef 	WAIT_OBJECT_1
#define 	WAIT_OBJECT_1	((WAIT_OBJECT_0)+1)
#endif	//	WAIT_OBJECT_1
#define 	WAIT_OBJECT_2	((WAIT_OBJECT_0)+2)
#ifndef 	PAGE_SIZE
#define 	PAGE_SIZE		(4096)
#endif	/*	PAGE_SIZE	*/
#define 	SINT24_MAX		(0x007FFFFF)
#define 	SINT24_MIN		(0x00800000)
#define 	UINT24_MAX		(0x00FFFFFF)

#ifndef 	MAX_PATH
#define 	MAX_PATH		(512)
#endif	//	MAX_PATH

//======================================================
//　マクロ
//======================================================
/*　NT_SUCCESSは、Windows Driver Kitのヘッダファイル　*/
#ifndef 	NT_SUCCESS
#define 	NT_SUCCESS(Status)	((NTSTATUS)(Status) >= 0)
#endif	/*	NT_SUCCESS	*/
#ifndef 	NT_VERIFY
#define 	NT_VERIFY(x)	(_ASSERT(NT_SUCCESS(x)))
#endif	/*	NT_VERIFY	*/

//======================================================
//　回避処置マクロ（ntstatus.h）
//======================================================
#ifndef 	STATUS_SUCCESS
#define 	STATUS_SUCCESS				((NTSTATUS)0x00000000L)
#endif	/*	STATUS_SUCCESS	*/

#ifndef 	STATUS_BUFFER_TOO_SMALL
#define 	STATUS_BUFFER_TOO_SMALL 	((NTSTATUS)0xC0000023L)
#endif	/*	STATUS_BUFFER_TOO_SMALL	*/

#ifndef 	STATUS_NOT_SUPPORTED
#define 	STATUS_NOT_SUPPORTED		((NTSTATUS)0xC00000BBL)
#endif	/*	STATUS_NOT_SUPPORTED	*/

#ifndef 	STATUS_INVALID_BUFFER_SIZE
#define 	STATUS_INVALID_BUFFER_SIZE	((NTSTATUS)0xC0000206L)
#endif	/*	STATUS_INVALID_BUFFER_SIZE	*/

//======================================================
//　Direct3D 関連マクロ
//======================================================
#ifndef 	STD_PI
#define 	STD_PI				((float)3.141592654f)
#define 	ToDegrees(radian)	((radian)*(180.0f/STD_PI))
#define 	ToRadians(degree)	((degree)*(STD_PI/180.0f))
#endif	/*	STD_PI	*/
#ifndef 	D3DCOLOR_ARGB
//　maps unsigned 8 bits/channel to D3DCOLOR
#define 	D3DCOLOR_ARGB(a,r,g,b) \
	((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#define 	D3DCOLOR_RGBA(r,g,b,a) D3DCOLOR_ARGB(a,r,g,b)
#define 	D3DCOLOR_XRGB(r,g,b)   D3DCOLOR_ARGB(0xff,r,g,b)
#endif	/*	D3DCOLOR_ARGB	*/

//======================================================
//　PCCS色
//======================================================
#define 	MAKE_PCCS_COLOR(r,g,b)	((r<<16)|(g<<8)|(b))
enum	PCCS_COLOR {
	PCCS_v1   = MAKE_PCCS_COLOR(182,30,85),
	PCCS_v18  = MAKE_PCCS_COLOR(16,93,163),
	PCCS_dk18 = MAKE_PCCS_COLOR(16,51,81),
	PCCS_p18  = MAKE_PCCS_COLOR(191,201,210),
	PCCS_lt18 = MAKE_PCCS_COLOR(101,145,192),
	PCCS_w    = MAKE_PCCS_COLOR(241,241,241),
};

#endif	/*	__UCONSTANTS_H__	*/
