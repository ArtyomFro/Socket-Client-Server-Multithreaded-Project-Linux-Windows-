#pragma once

class TH1 {
private:
	std::string InputUse;
public:
	std::mutex mtx;
    bool CheckString();
    std::string InsertString();
	void SortString();
	void InputString();
};
