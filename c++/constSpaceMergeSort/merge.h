//
// Created by moonmaster on 3/9/16.
//

#ifndef SORT_MERGE_H
#define SORT_MERGE_H
#include <vector>
#include <iostream>

template <class elements>
class merge {

public:
    elements sort(elements & array);
    elements mergeSort(elements & array, long low, long mid, long high);
    void print ();

private:
    elements temp;
};


#endif //SORT_MERGE_H
