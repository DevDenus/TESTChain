#include "Block.h"

std::string sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

Block::Block(unsigned index_in, const std::string &data_in) : index(index_in), data(data_in)
{
    nonce = -1;
    timestamp = time(nullptr);
}

std::string Block::get_hash()
{
    return hash;
}

std::string Block::get_block()
{
    std::stringstream ss;
    ss << "Block index: " << index << std::endl;
    ss << "Block edited: " << std::ctime(&timestamp) << std::endl;
    ss << "Block data:" << std::endl;
    ss << data << std::endl;
    return ss.str();
}

void Block::mine_block(unsigned difficulty)
{
    std::string str(difficulty, '0');

    do
    {
        ++nonce;
        hash = calculate_hash();
    } while (hash.substr(0, difficulty) != str);

    std::cout << "Block mined: " << hash << std::endl;
}

std::string Block::calculate_hash() const
{
    std::stringstream ss;
    ss << index << timestamp << data << nonce << previous_hash;
    return sha256(ss.str());
}
