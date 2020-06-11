/*
* Author: Marko Njegomir
* Project: Program that converts the binary code of any file into multiple zerobytes files.
*		   These zerobytes files contain all the binary code in the names of the files in ASCII format.
*		   Because the code is in the name, the file appears to take up 0 bytes of storage (although name itself must be stored)
*		   If these zerobytes files are stored on the cloud, then the company that provides the service will not notice
*		   that these files take up space.
*/


#include <string>
#include "ZeroBytesConversion.h"

int main(int argc, char* argv[]) {

	std::string filename("infile.zip");
	ConvertToZerobytes(filename,"nesto");


	return 0;
}