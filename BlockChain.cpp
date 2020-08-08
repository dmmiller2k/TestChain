#include "Blockchain.h"

Blockchain::Blockchain(uint32_t nDifficulty /*= 6*/)
	: nDifficulty_(nDifficulty)
{
	vChain_.emplace_back(0, "Genesis Block");
}

void Blockchain::AddBlock(Block bNew) {
	bNew.sPrevHash = GetLastBlock_().GetHash();
	bNew.MineBlock(nDifficulty_);
	vChain_.emplace_back(bNew);
}