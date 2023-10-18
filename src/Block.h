#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include <ctime>

class Block
{
public:
    std::string previous_hash;

    Block(unsigned index_in, const std::string &data_in);

    std::string get_hash();
    std::string get_block();
    void mine_block(unsigned difficulty);

private:
    unsigned index;
    std::string hash;
    long long nonce;
    time_t timestamp;
    std::string data;

    inline std::string calculate_hash() const;
};

#endif
