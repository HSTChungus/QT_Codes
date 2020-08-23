#!/bin/bash

Path="$(pwd)"
PathCorrect="$Path/Key_Files/"

echo $PathCorrect

Search="cts/"

Loc1=$(awk -v a="$PathCorrect" -v b="$Search" 'BEGIN{print index(a,b)}')

echo "Loc1 = $Loc1"

P_S=${#PathCorrect}
echo "P_S = $P_S"

P_C=${PathCorrect:Loc1+5}
echo "P_C = $P_C"

Loc2=$(awk -v a="$P_C" -v b="/" 'BEGIN{print index(a,b)}')
echo "Loc2 = $Loc2"

File_Name=${PathCorrect:Loc1+3:Loc2+1}
echo "Filename = $File_Name"

Pi_Path="/home/pi/QT_Projects"
Slash="/"

Final_Path=$Path$Slash$File_Name$Slash
echo "Final_Path = $Final_Path"

if [ ! -d $Final_Path ]; then
	mkdir $File_Name
	echo "Made $File_Name"
else
	echo "$File_Name Exists"
	rm -r $File_Name
	echo "Removed"
	mkdir $File_Name
	echo "Made $File_Name"
	
fi

cp -t $Final_Path Full_in_QT.pro globals.cpp globals.h home_screen.cpp home_screen.h home_screen.ui main.cpp time_select.cpp time_select.h time_select.ui

echo "Copied Successfully"

Pro=".pro"
Pro_FN=$File_Name$Pro
Pro_File_Path=$Final_Path$Pro_FN

sed -i -e 's/beam/pi/g' $Pro_File_Path

echo "File Edited"

scp -r $Final_Path pi@192.168.10.111:$Pi_Path

echo "Files Copied"

ssh pi@192.168.10.111 "pwd"
ssh pi@192.168.10.111 "cd /home/pi/QT_Projects/$File_Name && qmake $Pro_FN && make"

echo "Files copied Successfully"




