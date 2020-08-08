#pragma once

#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <deque>
#include "Block.h"

using namespace std;

class Blockchain
{
	uint32_t nDifficulty_;
	deque<Block> vChain_;

	const Block& GetLastBlock_() const { return vChain_.back(); }

public:
	Blockchain(uint32_t nDifficulty = 6);

	void AddBlock(Block bNew);
};

#endif	// TESTCHAIN_BLOCKCHAIN_H