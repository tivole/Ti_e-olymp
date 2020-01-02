// (c) Tivole

// 6766

#include <assert.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int nrows, ncols;
vector<vector<int>> data;
vector<pair<bool, int>> moves;

bool invalid(int r, int c)
{
	return data[r][c] != ncols * r + c + 1;
}

void move(bool d, int i)
{
	moves.push_back(make_pair(d, i));
	if (d) for (int col = 0, loc = ncols - 1; col < loc; ++col, --loc) swap(data[i][col], data[i][loc]);
	else for (int row = 0, wor = nrows - 1; row < wor; ++row, --wor) swap(data[row][i], data[wor][i]);
}

int main()
{
	int ncases;
	assert(1 == scanf("%d", &ncases));
	while (ncases-- > 0)
	{
		// read dimensions, allocate data structures
		assert(2 == scanf("%d%d", &ncols, &nrows));
		vector<vector<int>>(nrows, vector<int>(ncols)).swap(data);
		vector<pair<bool, int>>().swap(moves);
		// read the input
		for (int row = 0; row < nrows; ++row)
			for (int col = 0; col < ncols; ++col) assert(1 == scanf("%d", &data[row][col]));
		// handle middle row
		if (nrows % 2 == 1)
			for (int col = 0, row = nrows / 2; col < ncols; ++col)
				if (invalid(row, col)) move(true, row);
		// handle middle column
		if (ncols % 2 == 1)
			for (int row = 0, col = ncols / 2; row < nrows; ++row)
				if (invalid(row, col)) move(false, col);
		// handle quads
		for (int row = 0, wor = nrows - 1; row < wor; ++row, --wor)
			for (int col = 0, loc = ncols - 1; col < loc; ++col, --loc)
			{
				if (invalid(row, col)) { move(true, wor); move(false, col); move(true, wor); move(false, col); }
				if (invalid(row, col)) { move(false, loc); move(true, row); move(false, loc); move(true, row); }
				if (invalid(row, col)) { move(false, col); move(true, row); move(false, col); move(true, row); }
				if (invalid(wor, loc)) { move(false, loc); move(true, wor); move(false, loc); move(true, wor); }
				if (invalid(wor, loc)) { move(false, loc); move(true, wor); move(false, loc); move(true, wor); }
				if (invalid(row, loc))
					if (col) { move(true, row); move(false, col); move(true, row); }
					else     { move(false, col); move(true, row); move(false, col); }
			}
		// verify a solution has been found
		bool possible = true;
		for (int row = 0; row < nrows; ++row)
			for (int col = 0; col < ncols; ++col)
				if (invalid(row, col)) possible = false;
		// print the answer
		if (possible)
		{
			printf("POSSIBLE %lu", moves.size());
			for (int i = 0; i < moves.size(); ++i) printf(moves[i].first ? " R%d" : " C%d", moves[i].second + 1);
			printf("\n");
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}