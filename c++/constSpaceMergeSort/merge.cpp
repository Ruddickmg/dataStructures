#include "merge.h"
#include <cmath>
#include <algorithm>

template <class elements>
elements merge<elements>::sort(elements & array) {

    long inc = 2, low = 0, high = 2;
    long length = array.size();
    temp.resize((unsigned long) length);

    while (inc < length) { // while the incriment is less then the length

        mergeSort(array, low, (low + high) / 2, high);

        high += inc;
        low += inc;

        if (high >= length){

            mergeSort(array, low, (low + length) / 2, length);
            mergeSort(array, low - inc, length - (length - low), length);

            inc *= 2;
            high = inc;
            low = 0;
        }
    }
    
    mergeSort(array, low, (low + length) / 2, length);

    return temp;
};

template <class elements>
elements merge<elements>::mergeSort(elements & array, long low, long mid, long high) {

    long low2 = mid, count = low;

    while (count < high && low < mid && low2 < high)

        temp[count++] = array[low] < array[low2] ? array[low++] : array[low2++];

    // fill out the remaining slots if we have passed the limits for either high
    while (low < mid)

        temp[count++] = array[low++];

    while (low2 < high) 
        
        temp[count++] = array[low2++];

    return temp;
}

template <class elements>
void merge<elements>::print() {

    std::cout << "[";

    if(temp.size()) {

        std::cout << temp[0];

        for (int i = 1; i < temp.size(); i += 1)

            std::cout << ", " << temp[i];

    } else std::cout << "empty";

    std::cout << "]" << std::endl;
}

template class merge<std::vector<int>>;