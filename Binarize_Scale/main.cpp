
#include <stdio.h>
#include "image.h"
#include "ipTool.h"

#define WIDTH  256
#define HEIGHT 256

#define MAXLEN 256

int main(int argc, char* argv[]){

	// input arguments should be larger or equal 2;
	if (argc<2)
	{
		  fprintf(stderr, "Please tell me the filter's name ^^\n");
		  exit(0);
		
	}
	// check whether the first input = "binarize";
	if (strncasecmp(argv[1],"binarize",MAXLEN)==0)
	{
		if (argc!=5)
		{
		  fprintf(stderr, "binarization require 3 arguments\n");
		  exit(0);
		}
		//binarize filter:
		char srcname[MAXLEN];
		char tgtname[MAXLEN];
		int threshhold;
		Image src;
		Image tgt;

		strcpy(srcname,argv[2]); // copy source file name;
		strcpy(tgtname,argv[3]); // copy target file name;
		threshhold=atoi(argv[4]);// set threshold value;  
		src.read(srcname);
		tgt.initialize(src.NR,src.NC); // NR=Number of Rows, NC=Number of Columns;
		ipTool::binarize(src,tgt,threshhold); // call binarize funtion;
		tgt.save(tgtname); // save target image file;
		exit(0);
	}
    // check weather first input = "scale"
    if (strncasecmp(argv[1], "scale", MAXLEN)==0)
    {
        if (argc!=4)
        {
            fprintf(stderr, "scale requires 2 arguments\n");
            exit(0);
        }
        //scale filter
        char srcname[MAXLEN];
        char tgtname[MAXLEN];
        Image src;
        Image tgt;
        
        strcpy(srcname, argv[2]);  //copy source file name;
        strcpy(tgtname, argv[3]);  //copy target file name;
        src.read(srcname);
        tgt.initialize(src.NR/2, src.NC/2);  //NR=number of rows, NC = number of columns;
        ipTool::scale(src, tgt);  //call scale function
        tgt.save(tgtname); //save target image file;
        exit(0);
    }
	fprintf(stderr, "Unknow Filter Name\n");
	return 0;

}
