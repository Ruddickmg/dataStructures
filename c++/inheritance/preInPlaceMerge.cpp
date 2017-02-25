///------------------------------------------------------------------------------------------------------------

//
// Created by moonmaster on 3/9/16.
//

#include "merge.h"
#include <cmath>
#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector

template <typename elements>
elements merge<elements>::sort(elements & array) {

    print(array);

    int inc = 2, low = 0, high = 2, length = array.size();

    std::cout << std::endl;

    while(inc < length){ // while the incriment is less then the length

        std::cout << std::endl <<  "---------------------- Merge " << inc << " ------------------------" << std::endl << std::endl;

        mergeSort(array, low, (low + high) / 2, high);
        high += inc;
        low += inc;

        if(high >= length){

            // sort the end of the end of the array, then merge it into the larger previous section
            std::cout << std::endl << "---------------------- end Merge  " << inc << " -----------------------" << std::endl << std::endl;
            mergeSort(array, low, (low + length) / 2, length);

            std::cout << std::endl << "---------------------- second Merge " << inc << " ------------------------" << std::endl << std::endl;
            mergeSort(array, low - inc, length - (length - low), length);

            inc *= 2;
            high = inc;
            low = 0;
        }
    }

    mergeSort(array, low, (low + length) / 2, length);
    return array;
};

template <typename elements>
void merge<elements>::mergeSort(elements & array, int low, int mid, int high) {

    int count = low, beg = low, low2 = mid, stop = high - 2;

    std::cout << std::endl << "start: ";

    print(array, low, low2, count, mid, high, beg);

    std::cout << std::endl;

    std::cout << "low: " << low << ", mid: " << mid << ", high: " << high << std::endl;

    while (count < high && low < high && low2 < high && low != low2) {

        if (array[low] > array[low2]) {

            std::cout << "count: " << count << ", low: " << array[low] << " is greater then low2: " << array[low2] << std::endl;

            std::swap(array[count++], array[low2++]);

            if ( low < count) {
                std::cout << "changing low to mid" << std::endl;
                low = mid;

            } else if (mid <= low && low == (low2 - 2)) {
                std::cout << std::endl << "   !!!!!!!!!!!!! ------- here --------- !!!!!!!!!!!!!" << std::endl << std::endl;
                std::cout << "swapping low (" << low << "): " << array[low] << " for low + 1 (" << (low + 1) << ") :" << array[low + 1] << std::endl;
                std::swap(array[low++], array[(low + 1)]);
                std::cout << "new low: " << low << std::endl;
            }

        } else {
            std::cout << "count: " << count << ", low: " << array[low] << " is not greater then low2: " << array[low2] << std::endl;
            std::swap(array[count++], array[low++]);
        }

        if(low2 <= low) {
            low = mid;
            std::cout << "changing low" << std::endl;
        }

        if(count == mid) { // <-- auto correct
            mid = low2;
            std::cout << "changing mid" << std::endl;
        }

        if(low == low2 && count < mid)
        	low = mid;

        print(array, low, low2, count, mid, high, beg);
        std::cout << std::endl;
    }
}

template class merge<std::vector<int>>;

//    // fill out the remaining slots if we have passed the limits for either high
//    while (low < mid) temp[count++] = array[low++];
/