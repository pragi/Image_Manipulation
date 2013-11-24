for src  in *.pgm;
do
# set target file name;
tgt=`basename $src` ;
echo converting $src to $tgt;
# run "AdaptThresh" function with ROI;
$1 AdaptThresh $src $tgt roi_adapt.txt;
done