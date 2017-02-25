/* ----------------------------------------------------------------------------------- *\

	Matrix holds map elements in a matrix for quick access during map analysis

\* ----------------------------------------------------------------------------------- */

module.exports = function () {

	matrix = {};

	return {

		insert: function (x, y, element) {

			if (!matrix[x]) {

				matrix[x] = {};
			}

			matrix[x][y] = element;

		    return matrix[x][y];
		},

		remove: function (x, y) {

			var element = this.position(x, y);

			if (element) {
				
				delete matrix[x][y]
			}

			return element;
		},

		get: function (x, y) {

			return matrix[x] ? matrix[x][y] : undefined;
		}
	};
};