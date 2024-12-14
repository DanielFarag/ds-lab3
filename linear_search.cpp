#include <iostream>
using namespace std;

/**
Implement linear search on an array.
(Bouns)
handle cases where the array contains multiple occurrences of the target element.
Display all indices where the target element is found.
*/
int linearSearch(int target, int data[], int size, int occurrences[]){
    int found = 0;

    for(int i = 0; i< size; i++){
        if(data[i] == target){
            occurrences[found++] = i;
        }
    }

    return found;
}

int main(){
    
    int size = 10;
    int elements[size] = {3, 5, 2, 1, 2, 3, 4, 5, 1, 2};
    int occurrences[size];


    for(int i = 2; i<=6; i+=2){
        int found = linearSearch(i, elements, size, occurrences);
        
        if(found == 0) return 0;
        
        cout << "Element: " << i << " is fonud at indexes N: ";
        for(int b = 0; b<found; b++){
            cout << occurrences[b] << ", ";
        }
        cout << endl;
    }

    /**
                            SAMPLE OUTPUT
        Element: 2 is fonud at indexes N: 2, 4, 9, 
        Element: 4 is fonud at indexes N: 6,
    */

    return 0;
}
