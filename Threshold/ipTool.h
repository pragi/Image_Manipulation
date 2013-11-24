// ipTool.h: interface for the ipTool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPTOOL_H__65F5F541_0319_42DF_9ABC_143FAB67972C__INCLUDED_)
#define AFX_IPTOOL_H__65F5F541_0319_42DF_9ABC_143FAB67972C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "image.h"
#include "ROI.h"

class ipTool  
{
public:
	static void GrayThresh(Image& src, ROI roi, Image& tgt);  // src: source image; tgt: target image; thresh: threshold value;
	static void Arithmetic(Image& src, ROI roi, Image& tgt);
	static void ColorThresh(Image& src, ROI roi, Image& tgt);
	static void AdaptThresh(Image& src, ROI roi, Image& tgt);
	ipTool();
	virtual ~ipTool();

};

#endif // !defined(AFX_IPTOOL_H__65F5F541_0319_42DF_9ABC_143FAB67972C__INCLUDED_)
