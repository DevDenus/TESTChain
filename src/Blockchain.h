#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain
{
public:
    Blockchain();

    void add_block(Block new_block);
    std::string get_blockchain();

private:
    unsigned difficulty;
    std::vector<Block> chain;

    Block get_last_block() const;
};

#endif
