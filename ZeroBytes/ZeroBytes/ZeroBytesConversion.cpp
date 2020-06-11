#include "ZeroBytesConversion.h"

void ConvertToZerobytes(std::string in_filename, std::string out_folder)
{
	/*
	* Id counter for the zero bytes program
	* it is used when a new zero bytes program is created because it can
	* spread accross multiple files
	*/
	int zbfile_id_cnt = 0;

	/*
	* Size of the id number of zerobytes files
	* Used to determine number of leading zeros
	*/
	int id_size;

	/*
	* Type of data that is stored in zerobytes program
	* If it is hexadecimal file then the value should be 1
	* For binary file value should be 0
	*/
	int zb_type = __HEX__;

	std::ifstream in(in_filename, std::ios::binary);
	//std::ofstream out("../temp/temp.bin", std::ios::binary);

	// clear the temporary directory where zerobytes program will be stored
	std::experimental::filesystem::remove_all("../zeroBytesProgram/");
	std::experimental::filesystem::create_directory("../zeroBytesProgram/");
	std::stringstream stream;
	char d;
	std::string s; /*= std::string(id_size - std::to_string(zbfile_id_cnt).length(), '0') + std::to_string(zbfile_id_cnt) + "_";*/
	std::string empty = "";
	std::string temp = "";
	while (in >> std::noskipws >> d) {

		if (s.length() > NAMESIZE)
		{
			s = std::string(ZB_ID_SIZE - std::to_string(zbfile_id_cnt).length(), '0') + std::to_string(zbfile_id_cnt) + "_" + s;
			std::ofstream out("../zeroBytesProgram/" + s);
			out.write((char*)&empty, 0);
			out.close();
			++zbfile_id_cnt;
			// make new string
			s = "";
		}
		if (zb_type == __BIN__)
		{
			s += std::bitset<8>(d).to_string();
		}
		else if (zb_type == __HEX__)
		{
			// using string strim as a way to get hexadecimal representation of the digit
			stream << std::hex << (int)d;
			temp = stream.str(); // helper variable for making sure all hex numbers have 2 digits
			if (temp.size() < 2)
			{
				temp = "0" + temp; // if the number has only one digit, add a leading zero
			}
			s += temp;
			stream.str(""); // clear the stream
		}
	}
	s = std::string(ZB_ID_SIZE - std::to_string(zbfile_id_cnt).length(), '0') + std::to_string(zbfile_id_cnt) + "_" + s;
	std::ofstream out("../zeroBytesProgram/" + s);
	out.write((char*)&empty, 0);
	out.close();
	in.close();

}



void ConvertFromZerobytes(std::string in_folder, std::string out_filename)
{

}
