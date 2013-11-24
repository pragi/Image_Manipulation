for src  in *.pgm;
do
# set target file name;
tgt=`basename $src` ;
echo converting $src to $tgt;
# run "binarize" function with threshold=100;
$1 binarize $src $tgt 100;
done