/*
 * GDI font definitions
 *
 * Copyright 1994 Alexandre Julliard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __WINE_FONT_H
#define __WINE_FONT_H

#include "gdi.h"

#include "pshpack1.h"

  /* GDI logical font object */
typedef struct
{
    GDIOBJHDR   header;
    LOGFONTW    logfont;
} FONTOBJ;

typedef struct {
    WORD	dfVersion;
    DWORD	dfSize;
    CHAR	dfCopyright[60];
    WORD	dfType;
    WORD	dfPoints;
    WORD	dfVertRes;
    WORD	dfHorizRes;
    WORD	dfAscent;
    WORD	dfInternalLeading;
    WORD	dfExternalLeading;
    BYTE	dfItalic;
    BYTE	dfUnderline;
    BYTE	dfStrikeOut;
    WORD	dfWeight;
    BYTE	dfCharSet;
    WORD	dfPixWidth;
    WORD	dfPixHeight;
    BYTE	dfPitchAndFamily;
    WORD	dfAvgWidth;
    WORD	dfMaxWidth;
    BYTE	dfFirstChar;
    BYTE	dfLastChar;
    BYTE	dfDefaultChar;
    BYTE	dfBreakChar;
    WORD	dfWidthBytes;
    DWORD	dfDevice;
    DWORD	dfFace;
    DWORD	dfReserved;
    CHAR	szDeviceName[60]; /* FIXME: length unknown */
    CHAR	szFaceName[60];   /* dito */
} FONTDIR16, *LPFONTDIR16;

#include "poppack.h"

#define FONTCACHE 	32	/* dynamic font cache size */

extern BOOL FONT_Init( UINT16* pTextCaps );
extern INT16  FONT_GetObject16( FONTOBJ * font, INT16 count, LPSTR buffer );
extern INT  FONT_GetObjectA( FONTOBJ * font, INT count, LPSTR buffer );
extern INT  FONT_GetObjectW( FONTOBJ * font, INT count, LPSTR buffer );
extern void FONT_LogFontATo16( const LOGFONTA* font32, LPLOGFONT16 font16 );
extern void FONT_LogFontWTo16( const LOGFONTW* font32, LPLOGFONT16 font16 );
extern void FONT_LogFont16ToA( const LOGFONT16* font16, LPLOGFONTA font32 );
extern void FONT_LogFont16ToW( const LOGFONT16* font16, LPLOGFONTW font32 );
extern void FONT_TextMetricATo16(const TEXTMETRICA *ptm32, LPTEXTMETRIC16 ptm16 );
extern void FONT_TextMetricWTo16(const TEXTMETRICW *ptm32, LPTEXTMETRIC16 ptm16 );
extern void FONT_TextMetric16ToA(const TEXTMETRIC16 *ptm16, LPTEXTMETRICA ptm32 );
extern void FONT_TextMetric16ToW(const TEXTMETRIC16 *ptm16, LPTEXTMETRICW ptm32 );
extern void FONT_TextMetricAToW(const TEXTMETRICA *ptm32A, LPTEXTMETRICW ptm32W );
extern void FONT_NewTextMetricEx16ToW(const NEWTEXTMETRICEX16*, LPNEWTEXTMETRICEXW);
extern void FONT_EnumLogFontEx16ToW(const ENUMLOGFONTEX16*, LPENUMLOGFONTEXW);

extern LPWSTR FONT_mbtowc(HDC, LPCSTR, INT, INT*, UINT*);

extern GdiFont WineEngCreateFontInstance(DC*, HFONT);
extern BOOL WineEngDestroyFontInstance(HFONT handle);
extern DWORD WineEngEnumFonts(LPLOGFONTW, DEVICEFONTENUMPROC, LPARAM);
extern BOOL WineEngGetCharWidth(GdiFont, UINT, UINT, LPINT);
extern DWORD WineEngGetFontData(GdiFont, DWORD, DWORD, LPVOID, DWORD);
extern DWORD WineEngGetGlyphIndices(GdiFont font, LPCWSTR lpstr, INT count,
				    LPWORD pgi, DWORD flags);
extern DWORD WineEngGetGlyphOutline(GdiFont, UINT glyph, UINT format,
				    LPGLYPHMETRICS, DWORD buflen, LPVOID buf,
				    const MAT2*);
extern UINT WineEngGetOutlineTextMetrics(GdiFont, UINT, LPOUTLINETEXTMETRICW);
extern BOOL WineEngGetTextExtentPoint(GdiFont, LPCWSTR, INT, LPSIZE);
extern BOOL WineEngGetTextExtentPointI(GdiFont, const WORD *, INT, LPSIZE);
extern BOOL WineEngGetTextMetrics(GdiFont, LPTEXTMETRICW);
extern BOOL WineEngInit(void);

#endif /* __WINE_FONT_H */
