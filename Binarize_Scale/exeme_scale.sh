for src  in *.pgm;
do
# set target file name;
tgt=`basename $src` ;
echo converting $src to $tgt;
# run "scale" function;
$1 scale $src $tgt;
done

