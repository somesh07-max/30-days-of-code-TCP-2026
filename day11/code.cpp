class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        // temporary arrays
        vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = l;

        // merge the two halves
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        // copy remaining elements
        while (i < n1)
            arr[k++] = left[i++];

        while (j < n2)
            arr[k++] = right[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        // sort left half
        mergeSort(arr, l, mid);

        // sort right half
        mergeSort(arr, mid + 1, r);

        // merge both halves
        merge(arr, l, mid, r);
    }
};
