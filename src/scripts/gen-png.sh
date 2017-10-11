#!/bin/bash

for i in `ls *.ompexp.dot`; do
	echo 'Processing:' $i
	newname=`echo ${i} | tr '.' '-'`
	echo 'New Name:' ${newname}
	dot -Tpng $i > ${newname}.png
done