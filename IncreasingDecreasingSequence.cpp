class Solution {
public:
	vector<int> findPermutation(string const& s) {
		if (s.empty()) {
			return {};
		}
		// minimum element we can assign to any position at the moment
		int min_elem = 1;
		// starting and ending index (inclusive) of the current block of
		// identical letters (which could be either 'D...D' or 'I...I')
		int block_start = 0, block_end = 0;
		int next; // index of the next character to be read
		vector<int> res(s.size() + 1);  // the result
		// process one block of identical letters at a time
		do {
			next = block_start + 1;
			// if the next character is equal to the one preceeding it, then
			// expand the current block by 1 character
			while (next < s.size() && s[next - 1] == s[next]) {
				++next;
				++block_end;
			}
			if ('D' == s[block_end]) {
				// found a block of letter 'D's`  
				// assign smallest possible values to
				// res[block_start], res[block_start + 1], ..., res[block_end], res[block_end + 1]
				// (note in this case there are (block size + 1) assignments)
				for (int i = block_end + 1; i >= block_start; --i) {
					res[i] = min_elem++;
				}
			}
			else {
				// found a block of letter 'I's
				// assign smallest possible values to
				// res[block_start], ..., res[block_end]
				// if there was no previous value assigned
				// (note in this case there are at most (block size) assignments)
				if (0 == res[block_start]) {
					// ^^ If res[block_start] contains a smaller value assigned
					// from a previous block of letter 'D's, then don't overwrite
					// that value. If otherwise, then assign to it the smallest
					// value possible.
					res[block_start] = min_elem++;
				}
				for (int i = block_start + 1; i <= block_end; ++i) {
					res[i] = min_elem++;
				}
			}
			// entering the next block
			block_start = block_end = next;
		} while (next < s.size());
		// If the very last block of letters is 'I...I', then the last position
		// of the result doesn't contain any value yet. Assign it the only value
		// possible.
		if (0 == res.back()) {
			res.back() = min_elem;
		}
		return res;
	}
};