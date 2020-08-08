// TestChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <iostream>
#include <chrono>
#include "Blockchain.h"

using namespace std;
using namespace chrono;

class AutoTimer
{
	chrono::system_clock::time_point start_;
	string label_;
public:
	AutoTimer(const string& label = "")
		: start_(system_clock::now())
		, label_(label)
	{
		if (!label_.empty())
			cout << "Starting " << label_ << endl;
	}
	~AutoTimer() {
		duration<double> dur = system_clock::now() - start_;
		if (!label_.empty())
			cout << label_ << ": ";
		cout << "Elapsed seconds = " << dur.count() << endl;
	}
};

int main()
{
	Blockchain bChain(5);

	{
		AutoTimer at("Block 1");
		cout << "Mining block 1..." << endl;
		bChain.AddBlock(Block(1, "Block 1 Data"));
	}

	{
		AutoTimer at("Block 2");
		cout << "Mining block 2..." << endl;
		bChain.AddBlock(Block(2, "Block 2 Data"));
	}

	{
		AutoTimer at("Block 3");
		cout << "Mining block 3..." << endl;
		bChain.AddBlock(Block(3, "Block 3 Data"));
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
