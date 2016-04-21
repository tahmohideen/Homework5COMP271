#include <iostream>
#include <array>
#include <cstring>
#include <fstream>
#include <stdlib.h>


using namespace std;

//for bubble sort, we need to pick a point in the array and then investigate the rest of the elements to see if we need to reorder them
//if we do this for every element, we should get an ordered specimen
void bubble_sort (int numbers [], int size)
{
    int counter=0; //comparisons counter
    int tracker = 0; //exchangers counter
    for (int i=0; i< size; i++)
    {
        for (int j=0; j< size-1; j++)
        {
            counter++;
            if (numbers[j]<numbers[j+1])
            {
                int norm = numbers[j+1];
                numbers[j+1]=numbers[j];
                numbers[j]=norm;
                tracker++;
            }
        }
    }
    cout <<"Exchanges:";
    cout <<tracker<<endl;
    cout<<"Comparisons:";
    cout << counter <<endl;
}

//for insertion we want to insert values at proper points so that we continuously are sorting smaller samples
void insertion_sort(int numbers[], int length)
{
    int counter=0; //comparisons counter
    int tracker = 0; //exchangers counter
    int x,y;// iterators
    for (int k=0; k<length; k++)
    {
        x=k;
        counter++;
        while (x>0 && numbers[x]<numbers[x-1])
        {
            y=numbers[x];
            numbers[x]=numbers[x-1];
            numbers[x-1]=y;
            x--;
            tracker++;
        }
    }
    cout <<"Exchanges:";
    cout <<tracker<<endl;
    cout<<"Comparisons:";
    cout << counter <<endl;
}

//for quick sort, we want to find our pivot first. then we want to examine each side. this is a recursive function. make sure that we partition properly
void quick_sort(int numbers[], int a, int b)
{
    int counter=0; //comparisons counter
    int tracker = 0; //exchangers counter
    int shrek = a; //iterators
    int donkey = b; //iterators
    int fiona;
    int pivot_location = (a+b)/2;
    int pivot = numbers[pivot_location];
    while (shrek<= donkey)
    {
        while (numbers[shrek]<pivot)
        {
            shrek++;
            counter++;
        }
        while (numbers[donkey]<pivot)
        {
            donkey--;
            counter++;
        }
        if (shrek<=donkey)
        {
            fiona = numbers[shrek];
            numbers[shrek]=numbers[donkey];
            numbers[donkey]=fiona;
            shrek++;
            donkey--;
            tracker++;
        }
    };
    if (a<donkey)
    {
        quick_sort(numbers,a,donkey);
    }
    if(shrek<b)
    {
        quick_sort(numbers,shrek,b);
    }
    cout <<"Exchanges:";
    cout <<tracker<<endl;
    cout<<"Comparisons:";
    cout << counter <<endl;
}
//here we implement shell sort, with the gap equal to half of the size. then we will swap elements across the gap.
void shell_sort(int numbers[], int x)
{
    int counter=0; //comparisons counter
    int tracker = 0; //exchangers counter
    int valley, a, b, c;
    for(valley=x/2; valley>0; valley/=2)
    {
        for (a =valley; a<x; a++)
        {
            counter++;
            for (b=a-valley; b>=0 && numbers[b]>numbers[b+valley]; b-=valley)
            {
                c = numbers[b];
                numbers[b] = numbers[b+valley];
                numbers[b+valley]=c;
                tracker++;
            }
        }
    }
    cout <<"Exchanges:";
    cout <<tracker<<endl;
    cout<<"Comparisons:";
    cout << counter <<endl;
}
//here we have a fnction to help merge our data so that we can call it in our merge sort function
void margerine(int numbers[], int a, int b, int c)
{
    int counter=0; //comparisons counter
    int tracker = 0; //exchangers counter
    int d,e,f;
    int G[10000];
    d=a;
    e=c+1;
    f=0;
    while(d<=c && e<=b)
    {
        if (numbers[a]<numbers[b])
        {
            G[f]=numbers[a++];
            tracker++;
            counter++;
        }
        else
        {
            G[f]=numbers[b++];
            tracker++;
        }
        f++;
    }
    while (d<=c)
    {
        G[f++]=numbers[a++];
    }
    while (e<=b)
    {
        G[f++]=numbers[b++];
    }
    for(d=a, e=0; d<=b; d++, e++)
    {
        numbers[d]=G[e];
    }
    cout <<"Exchanges:";
    cout <<tracker<<endl;
    cout<<"Comparisons:";
    cout << counter <<endl;
}
void merge_sort(int numbers[], int a, int b)
{
    int c;
    if (a<b)
    {
        c=(a+b)/2;
        merge_sort(numbers,a,c);
        merge_sort(numbers,c+1,b);
        margerine(numbers,a,c,b);
    }
}


int main()
{
    //we are going to ask the user which file they wish to sort and how they wish to sort it
    string input;
    int numbers[10000];
    string numberology;
    cout << "Hello sir or madam. Which set of numbers would do you wish to sort? Choose: NearlySorted, FewUnique, Random, or Reversed. Do not forget to enter file as '.txt'"<<endl;
    cin >> numberology;
    //open file based on list chosen. store numbers into vector
    ifstream in;
    in.open(numberology);
    if (in.is_open())
    {
        cout<< "Try re-entering the file-name:"<< endl;
        cin >> numberology;
    }
    char * number_array = new char[100];
    int temp;
    while (in.peek()!=EOF)
    {
        for (int i=0; i<10000; i++)
        {
            in.getline(number_array,100,' ');
            temp = atoi(number_array);
            numbers[i]=temp;
        }
        in.clear();
        in.close();
    }

    //now ask for the search method you wish to implement. for each method, make a loop calling the proper functions, as wll as a print function to a file
    cout <<"How would you like to sort today? Choose: bubble, insert, quick, shell, or merge"<< endl;
    cin >> input;
    if (input == "bubble")
    {
        bubble_sort (numbers, 10000);
    }
    else if (input == "insert")
    {
        insertion_sort(numbers, 10000);
    }
    else if (input =="quick")
    {
        quick_sort(numbers, 0, 10000);
    }
    else if(input == "shell")
    {
        shell_sort(numbers,10000);
    }
    else if (input == "merge")
    {
        merge_sort(numbers,0,10000);
    }
}
