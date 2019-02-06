for oldname in *
do
  newname=`echo $oldname | sed -e 's/.txt//g'`
  mv "$oldname" "$newname"
done
