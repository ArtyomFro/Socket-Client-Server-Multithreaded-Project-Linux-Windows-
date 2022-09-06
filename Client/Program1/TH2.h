#pragma once
class TH2 {
private:

public:
	int sum = 0;
	void ClearBuffer(std::string& Buffer);
	void DisplayString(std::string& Buffer);
	void CountSum(std::string& Buffer);
};