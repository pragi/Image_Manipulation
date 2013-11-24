for src  in *.ppm;
do
# set target file name;
tgt=`basename $src` ;
echo converting $src to $tgt;
# run "ColorThresh" function with ROI;
$1 ColorThresh $src $tgt roi_color.txt;
done