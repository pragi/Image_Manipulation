for src  in *.pgm;
do
# set target file name;
tgt=`basename $src` ;
echo converting $src to $tgt;
# run "Arithmetic" function with ROI;
$1 Arithmetic $src $tgt roi_arith.txt;
done