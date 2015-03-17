#ifndef DLLNODE_H
#define DLLNODE_H

#include "Position.h"

class DLLNode : public Position
{
private:
    DLLNode * next;
    DLLNode * prev;

public:
    DLLNode(int, DLLNode*, DLLNode*);
};

#endif
