#pragma once

#ifndef _UN_M_PAK_H     
#define _UN_M_PAK_H    
#include <iostream>    
#include <string>

class unMPakLibTool
{



	int getFileSize(const char* filename);


public:
	bool unMpak(std::string inMpak);


public:
	bool PackMpak(std::string piePath,std::string runPath,std::string outfilePath);


};
#endif // !_UN_M_PAK_H   
