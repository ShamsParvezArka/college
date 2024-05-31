void merge_sort(int list[], size_t size);
void merge_sort_ex(int list[], size_t left, size_t right);
void merge_sort_cat(int list[], size_t left, size_t right);

int main() {
	int container[5] = { 3, 1, 4, 1, 5 };
	merge_sort(container, 5);

	for (int i = 0; i < 5; i++)
		printf("%d ", container[i]);
}

void merge_sort(int list[], size_t size) {
	return merge_sort_ex(list, 0, size - 1);
}

void merge_sort_ex(int list[], size_t left, size_t right) {
	if (left < right) {
		size_t mid = left + (right - left) / 2;	

		merge_sort_ex(list, left, mid);
		merge_sort_ex(list, mid + 1, right);
		merge_sort_cat(list, left, mid, right);
	} else
		return;
}

void merge_sort_cat(int list[], size_t left, size_t mid, size_t right) {
	size_t left_len = mid - left + 1;
	size_t right_len = right - mid;
	int *tmp_list_left = malloc(sizeof(int) * left_len);
	int *tmp_list_right = malloc(sizeof(int) * right_len);

	for (int i = 0; i < left_len; i++)
		tmp_list_left[i] = list[left + i];

	for (int i = 0; i < right_len; i++)
		tmp_list_right[i] = list[mid + 1 + i];

	for (int i = 0, j = 0, k = left; k <= right; k++) 
	{
		if ((i < left_len) && 
			(j >= right_len || tmp_list_left[i] <= tmp_list_right[j])) {
			list[k] = tmp_list_left[i];
			i++;
		} else {
			list[k] = tmp_list_right[j];
			j++;
		}
	}
}