#include "Blockchain.h"
#include "Block.h"

Blockchain::Blockchain()
{
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 5;
}

void Blockchain::add_block(Block new_block)
{
    new_block.previous_hash = get_last_block().get_hash();
    new_block.mine_block(difficulty);
    chain.push_back(new_block);
}

std::string Blockchain::get_blockchain()
{
    std::stringstream ss;
    for (auto block : chain)
    {
        ss << "#################" << std::endl;
        ss << block.get_block() << std::endl;
    }
    return ss.str();
}

Block Blockchain::get_last_block() const
{
    return chain.back();
}
