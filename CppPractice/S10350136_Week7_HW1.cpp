#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 10
int insertionSort(int*);
int main(){
    int ary[SIZE];
    int i,j;
    srand(unsigned(time(NULL)));
    for (i=0; i<SIZE; i++){
        ary[i] = rand() % 100 + 1;
        }
    cout<< "Original Array ..." << endl;
    for (i=0; i<SIZE; i++) {
        cout<< setw(4) << ary[i];
        }
    cout<< endl;
    insertionSort(ary);
    cout<< endl<< endl;
    
    return 0;
}
int insertionSort(int* a){
    int i,j;
    int temp;
    cout<< "sorting..." << endl;
    for (i=1; i<SIZE; i++) {
        temp = a[i];
        for (j=i; a[j-1]>=temp && j>0; j--){
        a[j] = a[j-1];}
        a[j] = temp;
        cout<< "#" << i<< " step: ";
        for (int k=0; k<=i; k++) {
            cout << setw(4) << a[k];
            }
    cout<< endl;
    }
    cout<< "\nSortedArray ..." << endl;
    for (i=0; i<SIZE; i++) {
        cout<< setw(4) << a[i];
        }
    cout<< endl;
    return 0;
}