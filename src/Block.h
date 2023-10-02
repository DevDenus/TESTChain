#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>

class Block
{
public:
    Block(const unsigned i, const std::string &h, const std::string &ph, const std::tm ts, const std::string &d) : index(i), hash(h), previous_hash(ph), timestamp(ts), data(d) {}
    const unsigned get_index();
    const std::string get_hash();
    const std::string get_previous_hash();
    const std::tm get_timestamp();
    const std::string get_data();

private:
    const unsigned index;
    const std::string hash;
    const std::string previous_hash;
    const std::tm timestamp;
    const std::string data;
};

#endif
