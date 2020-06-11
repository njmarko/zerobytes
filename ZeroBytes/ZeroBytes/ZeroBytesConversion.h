#pragma once
/*
* Author: Marko Njegomir
* Project: Program that converts the binary code of any file into multiple zerobytes files.
*		   These zerobytes files contain all the binary code in the names of the files in ASCII format.
*		   Because the code is in the name, the file appears to take up 0 bytes of storage (although name itself must be stored)
*		   If these zerobytes files are stored on the cloud, then the company that provides the service will not notice
*		   that these files take up space.
*/

#include <string>

/**
* This function loads the binary file and converts it to multiple zerobytes files
* that contain the binary code in the name of the file in the ASCII format.
* Each file has an unique identifier that specifies the order in which the files were formed.
* @param in_filename string destination of the file that is about to be converted
* @param out_folder string destination of the folder where zerobytes files will be placed
*/
void ConvertToZerobytes(std::string in_filename, std::string out_folder);

/**
* This function loads the binary ASCII code from the names of zerobytes files in the specified folder
* and creates the original file.
* Each file has an unique identifier that specifies the order in which the files were formed.
* @param in_folder string destination of the folder that contains zerobytes files that will be loaded
* @param out_filename string destination and name of the file that will be created from the loaded code
*/
void ConvertFromZerobytes(std::string in_folder, std::string out_filename);

