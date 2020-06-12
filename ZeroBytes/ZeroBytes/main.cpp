/*
* Author: Marko Njegomir         
* Email:  njmarko1991@gmail.com
* Project: Program that converts the binary code of any file into multiple zerobytes files.
*		   These zerobytes files contain all the binary code in the names of the files in ASCII format.
*		   Because the code is in the name, the file appears to take up 0 bytes of storage (although name itself must be stored)
*		   If these zerobytes files are stored on the cloud, then the company that provides the service will not notice
*		   that these files take up space.
*/


#include <string>
#include "ZeroBytesConversion.h"

int main(int argc, char* argv[]) {

	/*
	* Zerobytes files will be generated based on this file.
	* Change this to test different file
	*/
	std::string filename("../originalFile/infile.zip");

	/*
	* Folder where zerobytes files will be placed
	*/
	std::string zerobytes_folder("../zeroBytesPrograms/");

	/*
	* Folder where the file will be reconstructed from the zerobytes files
	*/
	std::string reconstructed_folder("../recreatedFiles/");

	// first the function that creates zerobytes files is called
	ConvertToZerobytes(filename, zerobytes_folder);

	// after that a function that converts the zerobytes files into the original file will be called
	ConvertFromZerobytes(zerobytes_folder, filename);

	return 0;
}