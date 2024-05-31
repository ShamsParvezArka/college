int bin_search(int haystack[], size_t size, int needle);
int bin_search_ex(int haystack[], int needle, size_t left, size_t right);

int bin_serach(int haystack[], size_t size, int needle) {
	return bin_search_ex(haystack, needle, 0, size);
}

int bin_search_ex(int haystack[], int needle, size_t left, size_t right) {
	if (left > right)
		return -1;

	size_t mid = left + (right - left) / 2;

	if (haystack[mid] > needle)
		bin_search_ex(haystack, needle, left, mid - 1);
	if (haystack[mid] < needle)
		bin_search_ex(haystack, needle, mid + 1, right);

	return (int) mid;
}