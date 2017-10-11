#!/bin/bash

for i in `ls *.dot`; do
	echo 'Processing:' $i
	newname=`echo ${i} | tr '.' '-'`
	echo 'New Name:' ${newname}
	dot -Tpdf $i > ${newname}.pdf
done