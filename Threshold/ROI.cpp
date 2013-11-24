#include "ROI.h"
#include <stdio.h>


ROI::ROI()
{
	this->roiArray = 0;
	this->totalROI = 0;
}

void ROI::ROIArray(char* filename, int filter)
{
	//filter = 0 for Gray/arith, 1 for Color, 2 for adaptive
	FILE *file = fopen(filename, "rt+");
	//the first digit of file must specify total ROI for that region
	fscanf(file, "%d", &this->totalROI);
	//create an array of ROIs based on number provided
	this->roiArray = new roi_info[totalROI];

	if (filter == 0){
		for (int i = 0; i < totalROI ; i++)
		{
			fscanf(file, "%d %d %d %d %d\n", &roiArray[i].x, &roiArray[i].y, &roiArray[i].sx, &roiArray[i].sy, &roiArray[i].T);
			//printf("%d %d %d %d \n", roiArray[i].x, roiArray[i].y, roiArray[i].sx, roiArray[i].sy, roiArray[i].T);
		}
	}
	else if (filter == 1){
		for (int i = 0; i < totalROI ; i++)
		{
			fscanf(file, "%d %d %d %d %d %d %d %d\n", &roiArray[i].x, &roiArray[i].y, &roiArray[i].sx, &roiArray[i].sy, &roiArray[i].T, &roiArray[i].red, &roiArray[i].green, &roiArray[i].blue);
		}
	}
	else if (filter == 2){
		for (int i = 0; i < totalROI ; i++)
		{
			fscanf(file, "%d %d %d %d %d %d %d\n", &roiArray[i].x, &roiArray[i].y, &roiArray[i].sx, &roiArray[i].sy, &roiArray[i].T, &roiArray[i].winsize, &roiArray[i].weight);
		}
	}
	else{
		fprintf(stderr, "Unknow Filter Name\n");
	}

}

bool ROI::inboundROI(const int x, const int y)
{
	for (int i=0; i<this->totalROI; i++)
	{
		if (x > roiArray[i].x && y > roiArray[i].y &&
			x < (roiArray[i].x + roiArray[i].sx) &&
			y < (roiArray[i].y + roiArray[i].sy) ) {
				return true;
		}
	}

	return false;
}

ROI::~ROI()
{
}
