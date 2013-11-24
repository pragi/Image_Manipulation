// ipTool.cpp: implementation of the ipTool class.
//
//////////////////////////////////////////////////////////////////////

#include "ipTool.h"
#include <iostream>
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ipTool::ipTool()
{

}

ipTool::~ipTool()
{

}

/* --------------------Binarization function---------------------------------*/
/*  Input: &src->Source Image, roi-> roi info, &tgt->Target Image;   */ 
void ipTool::GrayThresh(Image& src, ROI roi, Image& tgt)
{

	for (int i = 0; i<roi.totalROI; i++){
		for (int j = roi.roiArray[i].x;	j < roi.roiArray[i].x + roi.roiArray[i].sx; j++){
			
			for (int k = roi.roiArray[i].y;	k < (roi.roiArray[i].y + roi.roiArray[i].sy); k++){
				
				if (src.inboundp(j,k)){
				//src(j,k,RED) = int((src(j,k,RED)+src(j,k,GREEN)+src(j,k,BLUE))/3);
					//std::cout << "threshold = "<< roi.roiArray[i].T << std::endl;
					//std::cout << "compare to = " << src(j,k,RED) << std::endl;
					
					if (src(j,k,RED)>=roi.roiArray[i].T){
						src(j,k,RED) = 255;
						//std::cout << "255" << std::endl;
					}
					else{
						src(j,k,RED) = 0;
						//std::cout << "0" << std::endl;
					}
				
					/*if (src(j,k,RED)>(roi.roiArray[i].T)){
						tgt(j,k,RED)=255;
						std::cout << "255" << std::endl;
					}
					else{
						tgt(j,k,RED)=0;
						std::cout << "0" << std::endl;
					}*/
				}
			}
		}
	}
}

void ipTool::Arithmetic(Image& src, ROI roi, Image& tgt)
{ 
	int value, temp;
	for (int i = 0; i<roi.totalROI; i++){
		value = roi.roiArray[i].T;
		for (int j = roi.roiArray[i].x;	j < roi.roiArray[i].x + roi.roiArray[i].sx; j++){
			
			for (int k = roi.roiArray[i].y;	k < (roi.roiArray[i].y + roi.roiArray[i].sy); k++){
				
				if (src.inboundp(j,k)){
					temp = src(j,k,RED) + value;
					if (temp > 255)
						src(j,k,RED) = 255;
					else if (temp < 0)
						src(j,k,RED) = 255;
					else
						src(j,k,RED) = temp;
				}
			}
		}
	}
}

void ipTool::ColorThresh(Image& src, ROI roi, Image& tgt)
{
	int tc, temp;
	double temp_Sqr;
	for (int i = 0; i<roi.totalROI; i++){
		tc = roi.roiArray[i].T;
		for (int j = roi.roiArray[i].x;	j < roi.roiArray[i].x + roi.roiArray[i].sx; j++){
			
			for (int k = roi.roiArray[i].y;	k < (roi.roiArray[i].y + roi.roiArray[i].sy); k++){

				if (src.inboundp(j,k)){

					temp_Sqr = ((src(j,k,RED) - roi.roiArray[i].red)*(src(j,k,RED) - roi.roiArray[i].red) + (src(j,k,BLUE) - roi.roiArray[i].blue)*(src(j,k,BLUE) - roi.roiArray[i].blue) + (src(j,k,GREEN) - roi.roiArray[i].green)*(src(j,k,GREEN) - roi.roiArray[i].green));
					temp = (int)sqrt(temp_Sqr);

					if (temp>= tc)
						(src(j,k,RED)) = (src(j,k,BLUE)) = (src(j,k,GREEN)) = 255;
					else
						(src(j,k,RED)) = (src(j,k,BLUE)) = (src(j,k,GREEN)) = 0;

				}
			}
		}
	}
}

void ipTool::AdaptThresh(Image& src, ROI roi, Image& tgt){
	int avg, thresh;
	int i;
	int w = roi.roiArray[i].winsize;
	int x = roi.roiArray[i].x;
	int y = roi.roiArray[i].y;

	for (int i = 0; i<roi.totalROI; i++){

		avg = ((src(x+w/2,y+w/2,RED)) + (src(x-w/2,y-w/2,RED)) - (src(x+w/2,y-w/2,RED)) + (src(x-w/2,y+w/2,RED)))/(w*w);

		thresh = (avg*roi.roiArray[i].weight) + (roi.roiArray[i].T);

		for (int j = roi.roiArray[i].x;	j < roi.roiArray[i].x + roi.roiArray[i].sx; j++){
			
			for (int k = roi.roiArray[i].y;	k < (roi.roiArray[i].y + roi.roiArray[i].sy); k++){
				
				if (src.inboundp(j,k)){
					
					if (src(j,k,RED)>=thresh){
						src(j,k,RED) = 255;
					}
					else{
						src(j,k,RED) = 0;
					}
			
				}
			}
		}
	}

}
