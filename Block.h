#pragma once

#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

using namespace std;

class Block
{
	uint32_t nIndex_;
	uint64_t nNonce_;
	string sData_;
	string sHash_;
	time_t tTime_;

	string CalculateHash_() const;

public:
	string sPrevHash;

	Block(uint32_t nIndexIn, const string& sDataIn);

	uint64_t nNonce() const { return nNonce_; }
	const string& GetHash() const { return sHash_; }

	void MineBlock(uint32_t nDifficulty);
};

#endif	// TESTCHAIN_BLOCK_H