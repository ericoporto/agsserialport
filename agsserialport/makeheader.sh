#!/bin/bash

HEADERFILE=agsserialport_ash.h

echo "#ifndef AGS_SERIALPORT_ASH_H" > "${HEADERFILE}"
echo "#define AGS_SERIALPORT_ASH_H"  >> "${HEADERFILE}"
echo ""  >> "${HEADERFILE}"

echo "const char *agsserialport_ash =" >> "${HEADERFILE}"

cat agsserialport.ash | while read -r line; 
do 
    clean_line=$(echo ${line} | tr "\r\n" " ")
    echo "\" ${clean_line}\\r\\n\"" >> "${HEADERFILE}" ; 
done 

echo ";"  >> "${HEADERFILE}"
echo ""  >> "${HEADERFILE}"

echo "#endif // AGS_SERIALPORT_ASH_H"  >> "${HEADERFILE}" 
