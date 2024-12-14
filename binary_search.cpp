#include <iostream>
using namespace std;
/**
Implement function for Binary searech algorithm using Iterative Method (loop)
*/
int binarySearch(int target, int data[], int size){
    int start = 0, end = size - 1, location = -1;

    while(start <= end){
        int current = (end + start) / 2;
        
        if(data[current] > target){
            end -= 1;
        }else if(data[current] < target){
            start += 1;
        }else {
            location = current;
            break;
        }

    } 

    return location;
}

int main(){
    
    int size = 14;
    int elements[size] = {4, 6, 9, 10, 12, 16, 18, 19, 22, 24, 26, 30, 32};

    int searching[] = {0, 3, 4, 12, 22, 16, 33, 32, 60};

    for(int i =0;i<9; i++){
        int found = binarySearch(searching[i], elements, size);

        if(found > -1){
            cout << searching[i] <<" found at " << found  << endl;
        }else{
            cout << searching[i] <<" NOT FOUND !! "  << endl;
        }
    }
    /**
                            SAMPLE OUTPUT
    0 NOT FOUND !! 
    3 NOT FOUND !! 
    4 found at 0
    12 found at 4
    22 found at 8
    16 found at 5
    33 NOT FOUND !! 
    32 found at 12
    60 NOT FOUND !! 
     */
    return 0;
}
