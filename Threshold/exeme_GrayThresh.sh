for src  in *.pgm;
do
# set target file name;
tgt=`basename $src` ;
echo converting $src to $tgt;
# run "GrayThresh" function with ROI;
$1 GrayThresh $src $tgt roi_gray.txt;
done