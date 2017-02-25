#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right )
{
    int j;

    for( int p = left; p <= right; p++ )
    {
        Comparable tmp = a[ p ];

        for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )

            a[ j ] = a[ j - 1 ];

        a[ j ] = tmp;
    }
}

template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;

    if( a[ center ] < a[ left ] )

        swap( a[ left ], a[ center ] );

    if( a[ right ] < a[ left ] )

        swap( a[ left ], a[ right ] );

    if( a[ right ] < a[ center ] )

        swap( a[ center ], a[ right ] );

    swap( a[ center ], a[ right - 1 ] );

    return a[ right - 1 ];
}

template <typename Comparable>
int partition (vector<Comparable> a, int left, int right, int pivot) {

    int i = left, j = right - 1;

    for( ; ; )
    {
        while( a[ ++i ] < pivot ) { }
        while( pivot < a[ --j ] ) { }

        if( i < j )

            swap( a[ i ], a[ j ] );

        else

            break;
    }

    return i;
};

template <typename Comparable>
void print (vector<Comparable> & a) {

    long end = a.size() - 1, i = 0;

    cout << '[';

    while (i < end) cout << a[i++] << ", ";

    cout << a[end] << ']' << endl;
}

template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if (left + 5 <= right) {

        Comparable pivot = median3(a, left, right);

        int i = partition(a, left, right, pivot);
        int j = right;

        swap(a[i], a[right - 1]); // Restore pivot

        while (i < j)

            if (a[++i] < pivot || pivot < a[--j])

                swap(a[i], a[j]);

        quicksort(a, left, i - 1);
    }

    insertionSort( a, left, right );
}

template <typename Comparable>
void quicksort( vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}

int main() {

    vector<int> array = {10000, 14443, 1, 5, 7, 19, 2, 50, 4, 899944949,  23, 98, 30, 11, 560,  31, 38, 103, 22, 17, 14, 8330, 67, 99, 25, 66, 32, 45, 83, 3};

    print(array);
    quicksort(array);
    print(array);

    return 0;
}