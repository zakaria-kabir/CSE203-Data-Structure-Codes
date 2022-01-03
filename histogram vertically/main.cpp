#include<bits/stdc++.h>
using namespace std;

void printhistogram(string file, int** histo, int*& elements, int bin, int& length) {
    int counter = 0, lenOfbin = 0, num = 0, lowest = 0, smallest = 0, range = 0, x = 0,high=0,up=0,young=0;
    int* arr = new int[bin];
    int max = INT_MIN, min = INT_MAX;
    fstream myfile;
    myfile.open(file);
    if (!myfile.is_open()) {
        cout << "File not found,please check again !" << endl;
    }
    else {
        //read file & get length of whole array
        while (myfile >> num)
        {
            length++;
        }
        myfile.close();
        //read file & store all elements to an array
        elements = new int[length];
        myfile.open(file);
        num = 0;
        while (myfile >> num)
        {
            elements[counter] = num;
            counter++;
        }
        myfile.close();
        //get min & max of all elements of the array
        for (int i = 0; i < counter; i++) {
            if (elements[i] > max)
                max = elements[i];
            if (elements[i] < min)
                min = elements[i];
        }
        young= smallest = lowest =min;
        high=up=max;
        x = max - min;
        range = x / bin;
        //allocating memory space for histogram
        for (int i = 0; i < bin; i++) {
            lenOfbin = 0;
            for (int j = 0; j < counter; j++) {
                if (elements[j] >= min && elements[j] <= min + range) {
                    lenOfbin++;
                    arr[i] = lenOfbin;
                    histo[i] = new int[lenOfbin];
                }
            }
            min += 1 + range;
        }
        //store elements into 2d array
        for (int i = 0; i < bin; i++) {
            for (int j = 0; j < arr[i];) {
                for (int k = 0; k < counter; k++) {
                    if (elements[k] >= lowest && elements[k] <= lowest + range) {
                        histo[i][j] = elements[k];
                        j++;
                    }
                }
            }
            lowest += 1 + range;
        }
//print vertically
        for(int i=max;i>=smallest;i--){
            cout<<right<<i<< " | ";
            for (int j = 0; j < counter; j++) {
                  // if (elements[j] >= high && elements[j] <= high - range) {
                       if(elements[j]>=i){
                        cout<<(char)254<<" ";

                       }
                       else{
                        cout<<"  ";
                       }
                  // }
            }
            cout<<endl;
            //max--;
           // high=(high -range)-1;

        }

        for (int i = 0; i < bin + 14; i++){
            cout << "---";
        }
            cout<<endl;
            cout<<"   ";
        for (int i = 0; i < counter; i++) {
            cout.width(2); // width for a number
           // cout << smallest << "-" << smallest + range << "  ";
           // smallest += 1 + range;
           cout<<elements[i];
    }

        //print histogram
        /*cout << "Histogram with bin size " << bin << " : " << endl;
        for (int i = 0; i < bin; ++i) {
            cout << smallest << "-" << smallest + range << " : ";
            for (int j = 0; j < arr[i]; ++j) {
                cout << histo[i][j] << " ";
            }
            if ((smallest + range) > max)
                break;
            cout << endl;
            smallest += 1 + range;
        }*/
        //delete heap memory
        delete[] arr;
        delete[] elements;
        for (int i = 0; i < bin; i++) {
            delete[] histo[i];
        }
    }
}

int main() {
    int numberofbin = 3;
    int len = 0;
    //cout << "enter number of bin: ";
    //cin >> numberofbin;
    int** histogram = new int* [numberofbin];
    int* allnumber = nullptr;
    string file = "z.txt";
    printhistogram(file, histogram, allnumber, numberofbin, len);
}
