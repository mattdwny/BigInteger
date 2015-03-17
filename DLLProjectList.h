#ifndef DLLPROJECTLIST_H
#define DLLPROJECTLIST_H

#include "ProjectList.h"
#include "DLLNode.h"

class DLLProjectList : public ProjectList {

private:
    DLLNode * head;
    DLLNode * tail;

public:
    DLLProjectList();
    ~DLLProjectList();

    void insertFirst(int);
    void insertLast(int);

    Position* first();
    Position* last();

    Position* before(const Position*);
    Position* after(const Position*);

    bool isFirst(const Position*);
    bool isLast(const Position*);

    bool isEmpty();

    int size();
};

#endif
