#!/bin/bash
# ./addFile.sh /path/to/your/file.cpp

# Get the filename (without extension) from the argument
filename=$(basename -- "$1")
filename="${filename%.*}"

# Add source file to Makefile
echo "$filename: client/src/$filename.cpp" >> Makefile
echo -e "\tg++ -c client/src/$filename.cpp -o \$(CLIENTBUILDDIR)/$filename.o\n" >> Makefile

# Add header file to Makefile
echo "client/include/$filename.h: ;" >> Makefile

# Add object file to Makefile
echo -e "$filename.o: client/include/$filename.h client/src/$filename.cpp" >> Makefile
echo -e "\tg++ -c client/src/$filename.cpp -o \$(CLIENTBUILDDIR)/$filename.o\n" >> Makefile
