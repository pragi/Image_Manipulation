
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "ipTool.h"

using namespace std;

#define WIDTH  256
#define HEIGHT 256

#define MAXLEN 256
//global varialbles;
//function declaration;


//function body;
/* The name of the variable argc stands for "argument count"; 
argc contains the number of arguments passed to the program. 
The name of the variable argv stands for "argument vector". 
A vector is a one-dimensional array, and argv is a one-dimensional
array of strings. Each string is one of the arguments that was passed to the program.*/ 




int main(int argc, char* argv[]){

	// input arguments should be larger or equal 2;
	if (argc<2)
	{
		fprintf(stderr, "Please tell me the filter's name ^^\n");
		exit(0);

	}

	if (argc!=5)
	{
		fprintf(stderr, "Filters require 3 arguments\n");
		exit(0);
	}

	char srcname[MAXLEN];
	char tgtname[MAXLEN];

	Image src;
	Image tgt;
	ROI roi;

	strcpy(srcname,argv[2]); // copy source file name;
	strcpy(tgtname,argv[3]); // copy target file name;


	src.read(srcname);
	tgt.initialize(src.NR,src.NC); // NR=Number of Rows, NC=Number of Columns;

	if (strncasecmp(argv[1],"GrayThresh",MAXLEN)==0){
		roi.ROIArray(argv[4],0); // second argument specifies graythresholding filter
		ipTool::GrayThresh(src,roi,tgt); // call binarize funtion;
	}
	else if (strncasecmp(argv[1],"Arithmetic",MAXLEN)==0){
		roi.ROIArray(argv[4],0);
		ipTool::Arithmetic(src,roi,tgt);
	}
	else if (strncasecmp(argv[1],"ColorThresh",MAXLEN)==0){
		roi.ROIArray(argv[4],1);
		ipTool::ColorThresh(src,roi,tgt);
	}
	else if (strncasecmp(argv[1],"AdaptThresh",MAXLEN)==0){
		roi.ROIArray(argv[4],2);
		ipTool::AdaptThresh(src,roi,tgt);
	}
	else
	{
		fprintf(stderr, "Unknow Filter Name\n");
		return 0;
	}

	src.save(tgtname); // save target image file;
	exit(0);
}

