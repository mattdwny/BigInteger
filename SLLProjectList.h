#ifndef SLLPROJECTLIST_H
#define SLLPROJECTLIST_H

#include "ProjectList.h"
#include "SLLNode.h"

class SLLProjectList : public ProjectList {

private:
    SLLNode * head;

public:
    SLLProjectList();
    ~SLLProjectList();

    void insertFirst(int);
    void insertLast(int);

    Position* first();
    Position* last();

    Position* before(Position*);
    Position* after(Position*);

    bool isFirst(Position*);
    bool isLast(Position*);

    bool isEmpty();

    int size();
};

#endif
