module.exports = function (input, context) {

    if (!isFunction(input)) {

        throw new Error("First argument of \"curry\" must be a function.", "tools/curry.js");
    }
    
    var inputs = input.length;

    return function curry () {

        var args = Array.prototype.slice.call(arguments, 0);

        if (args.length >= inputs) {

            return input.apply(context, args);

        } else {

            return function curried () {
 
                var args2 = Array.prototype.slice.call(arguments, 0);

                return curry.apply(context, args.concat(args2)); 
            }
        }
    };
};