class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero = 0, one = 0, two = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0) zero++;
            else if(arr[i] == 1) one++;
            else two++;
        }

        int index = 0;

        // place 0s
        for(int i = 0; i < zero; i++){
            arr[index++] = 0;
        }

        // place 1s
        for(int i = 0; i < one; i++){
            arr[index++] = 1;
        }

        // place 2s
        for(int i = 0; i < two; i++){
            arr[index++] = 2;
        }
    }
};
