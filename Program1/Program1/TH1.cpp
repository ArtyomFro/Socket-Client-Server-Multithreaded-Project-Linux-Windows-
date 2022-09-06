#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <mutex>
#include "TH1.h"

bool TH1::CheckString() {
	for (int i = 0; i < InputUse.size(); i++) {
		bool isa = isdigit(InputUse[i]);
		if (isa == false || InputUse.size() > 64) {
			return true;
		}
	}
	return false;
}

std::string TH1::InsertString() {
	for (int i = 0; i < InputUse.size(); i++) {
		if (InputUse[i] % 2 == 0 && isdigit(InputUse[i])) {
			InputUse.erase(i, 1);
			InputUse.insert(i, "KB");
		}
	}
	return InputUse;
}

void TH1::SortString() {
	std::stable_sort(InputUse.begin(), InputUse.end(), std::greater<char>());
}


void TH1::InputString() {
	std::cin >> InputUse;
}
