#pragma once
#include <string>
#include <iostream>
#include "TH2.h"

void TH2::ClearBuffer(std::string& Buffer) {
	Buffer.clear();
}

void TH2::DisplayString(std::string& Buffer) {
	std::cout << Buffer << std::endl;
}

void TH2::CountSum(std::string& Buffer) {
	for (int i = 0; i < Buffer.size(); i++) {
		if (isdigit(Buffer[i])) {
			sum += std::stoi(Buffer.substr(i, 1));
		}
	}
}
