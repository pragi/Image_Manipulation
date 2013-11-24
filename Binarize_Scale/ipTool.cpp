// ipTool.cpp: implementation of the ipTool class.
//
//////////////////////////////////////////////////////////////////////

#include "ipTool.h"

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
/*  Input: &src->Source Image, &tgt->Target Image, thresh->threshold hold;   */ 
void ipTool::binarize(Image &src, Image &tgt, int thresh)
{

	for(int i=0;i<tgt.NR;i++){
		for(int j=0;j<tgt.NC;j++){		
			if (src(i,j,RED)>thresh)
				tgt(i,j,RED)=255;
			else
				tgt(i,j,RED)=0;
		}
	}	

}

/*-----------------------Scale Function--------------------------------------*/
/*-----Input: &src->Source Image, &tgt->Target Image ------------------------*/

void ipTool::scale(Image &src, Image &tgt)
{
    int x, y, x2, y2;
    
    int tgt_nr, tgt_nc;
    
//    int p, q;
    
    tgt_nr = src.NR / 2;
    tgt_nc = src.NC / 2;
    
    for (y = 0; y < tgt_nc; y++) {
        y2 = 2 * y;
        for (x = 0; x < tgt_nr; x++){
            x2 = 2 * x;
            
//            p = AVERAGE(src[y2*src.NR + x2], src[y2*src.NR + x2 + 1]);
//            q = AVERAGE(src[(y2+1)*src.NR + x2], src[(y2+1)*src.NR + x2 + 1]);
//            tgt[y*tgt_nr + x] = AVERAGE(p, q);
            tgt(y,x) = (src(y2, x2) + src(y2 , (x2 + 1)) + src((y2+1), x2) + src((y2+1),(x2 + 1))) /4;
        }
    }
    
}





