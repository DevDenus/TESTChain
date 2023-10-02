#include "Block.h"

const unsigned Block::get_index()
{
    return index;
}

const std::string Block::get_hash()
{
    return hash;
}

const std::string Block::get_previous_hash()
{
    return previous_hash;
}

const std::tm Block::get_timestamp()
{
    return timestamp;
}

const std::string Block::get_data()
{
    return data;
}
