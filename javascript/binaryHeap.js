/* ------------------------------------------------------------------------------------------------------*\
    
    binaryHeap.js takes a string as an optional argument, this string is used as the name of a property 
    in a potential object to be compared when assessing its value in relation to the 
    other heap elements. its second argument is a comparison, which is a function that compares values 
    in the heap in a way specified by the function

\* ------------------------------------------------------------------------------------------------------*/

module.exports = function (comparison) {

    var comparison = comparison || function (number) {

        return number;
    };

    var heap = [], max = false;

    // swaps the parent index with the child, returns child's new index (parent index)
    // subtract one from each input to compensate for the array starting at 0 rather then 1
    var swap = function (heap, index, parentIndex) {

        if (isNaN(index) || isNaN(parentIndex)) {

            throw new Error("Invalid index supplied to swap in heap, index must be a number", "tools/binaryHeap.js");
        }

        var i = index - 1;
        var parent = parentIndex - 1;

        heap[i] = heap.splice(parent, 1, heap[i])[0];

        return heap;
    };

    // get the value at the input index, compensate for whether there is a property being accessed or not
    var value = function (heap, index) { 

        return comparison(heap[index - 1]);
    };

    // calculate the parent index
    var parent = function (index) {

        if (isNaN(index)) {

            throw new Error("Invalid index supplied to parent in heap", "tools/binaryHeap.js");
        }

        return Math.floor(index / 2);
    };

    // calculate the indexes of the left and right
    var left = function (i) {

        return i * 2;
    };

    var right = function (i) {

        return left(i) + 1;
    };

    var inequality = function (heap, l, r) {

        var lv = value(heap, l);
        var rv = value(heap, r);

        return max ? lv > rv : lv < rv;
    };

    var bubble = function (heap, index) {

        var parentIndex = parent(index);

        while (index > 1 && inequality(heap, index, parentIndex)) {

            heap = swap(heap, index, parentIndex);

            index = parentIndex;

            parentIndex = parent(index);
        }

        return heap;
    };

    var order = function (heap, index) {

        if (isNaN(index)) {

            throw new Error("Invalid index supplied to order in heap, index must be a number.", "tools/binaryHeap.js");
        }

        var child = index;
        var length = heap.length;
        var l = left(index);
        var r = right(index);

        while (length > l) {

            child = length > r && inequality(heap, r, l) ? r : l;

            heap = swap(heap, index, child);
            
            index = child;
            l = left(index);
            r = right(index);
        }

        return child === length ? heap : bubble(swap(heap, child, length), child);
    };

    return {

        heap: heap,

        // make a max heap instead of a min heap;
        setToMax: function () {

            max = true; 

            return this;
        },
        
        setToMin: function () {

            max = false;

            return this;
        },
        
        // add a value to the heap
        push: function (value) {

            heap.push(value);

            heap = bubble(heap, heap.length);

            return this;
        },

        // set which property to order by
        setProperty: function (p) {

            property = p;

            return this;
        },

        // remove and return the top item from the heap
        pop: function () {

            return order(heap, 1).pop();
        },

        // return the first value of the heap (lowest)
        min: function () {

            return heap[0];
        },

        // return the amount of elements in the heap (array)
        size: function () {

            return heap.length;
        },

        // reset heap
        clear: function () {

            heap = [];
        },

        test: function () {

            var success, results = [];
            var scope = this;

            var getRandom = function (min, max) {

                min = Math.ceil(min);
                max = Math.floor(max);

                return Math.floor(Math.random() * (max - min)) + min;
            };

            var randomList = function (length) {

                var list = [];
                var l = length;

                while (l--) {

                    list.push(getRandom(1, length));
                }

                return list;
            };

            var result = function (name, bool) {

                if (bool) {

                    console.log(name + ": Success");

                } else {

                    console.log(name + ": Failed");
                }

                return bool;
            };

            var test = function (compare, heap) {

                var previous = heap.pop();
                var current = heap.pop();

                while (heap.size() && compare(current, previous)) {

                    previous = current;

                    current = heap.pop();
                }

                return heap
            };

            var runTest = function (name, amount, heap, compare) {

                randomList(amount).forEach(function (number) {

                    heap.push(number);
                });

                return result(name, !test(compare, heap).size());
            };

            console.log("---=== Testing BinaryHeap ===---");

            this.clear();
            this.setToMax();

            results.push(runTest("Max", 1000, this, function (current, previous) {

                return current <= previous;
            }));

            this.clear();
            this.setToMin();

            results.push(runTest("Min", 1000, this, function (current, previous) {

                return current >= previous;
            }));

            success = results.reduce(function (previous, current) { 

                return previous && current; 

            }, true);

            if (success) {

                console.log("All tests were successful.");

            } else {

                console.log("Not all tests were successful.");
            };

            console.log("------====================------");
            console.log("");

            this.clear();

            return success;
        }
    };
};