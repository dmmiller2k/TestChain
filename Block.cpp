#include "Block.h"
#include "sha256.h"

#include <ctime>
#include <sstream>
#include <chrono>

Block::Block(uint32_t nIndexIn, const string& sDataIn)
	: nIndex_(nIndexIn)
	, nNonce_(-1)
	, sData_(sDataIn)
	, tTime_(time(nullptr))
{}

inline string Block::CalculateHash_() const {
	stringstream ss;
	ss << sPrevHash << nIndex_ << tTime_ << sData_ << nNonce_ ;
	return sha256(ss.str());
}

void Block::MineBlock(uint32_t nDifficulty)
{
	string str(nDifficulty, '0');

	do {
		++nNonce_;
		sHash_ = CalculateHash_();
	} while (sHash_.substr(0, nDifficulty) != str);

	cout << "Block mined (" << nNonce_ << " iterations): " << sHash_ << endl;
}