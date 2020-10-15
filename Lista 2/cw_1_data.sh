#!/bin/bash
# %u oznacza ze podaje numer dnia tygodnia
dzien=`date +%u`
echo Dzis jest 
if [ $dzien -le 5 ]
then
    echo  dzień ROBOCZY
else
    if [ $dzien -eq 6 ]
    then
	echo  SOBOTA!
    else
	echo  NIEDZIELA!
    fi
fi
