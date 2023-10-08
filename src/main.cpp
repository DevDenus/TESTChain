#include <iostream>
#include "Blockchain.h"

using namespace std;

int main()
{
    Blockchain bChain = Blockchain();

    cout << "Mining 1 block" << endl;
    bChain.add_block(Block(1, "Block 1 data"));

    cout << "Mining 2 block" << endl;
    bChain.add_block(Block(2, "Block 2 data"));

    cout << "Mining 3 block" << endl;
    bChain.add_block(Block(3, "Block 3 data"));

    cout << bChain.get_blockchain() << endl;

    return 0;
}
