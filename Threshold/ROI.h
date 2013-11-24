
#ifndef _ROI_HPP_
#define _ROI_HPP_ 

#pragma once

class roi_info
{
public:
	int x;
	int y;
	int sx;
	int sy;
	int T;
	int red;
	int green;
	int blue;
	int winsize;
	int weight;
};


class ROI
{
public:
	roi_info* roiArray;
	int totalROI;

	void ROIArray(char* filename, int filter);
	bool inboundROI(const int x, const int y);
	ROI();
	virtual ~ROI();
};

#endif