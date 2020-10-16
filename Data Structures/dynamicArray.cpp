#include <iostream>
#include "dynamicArray.h"

using std::cout;
using std::endl;

DynamicArray::DynamicArray() {
    this->length = 0;
    this->size = 1;
    this->arr = new int[size];
    for (int i = 0; i < size; ++i) this->arr[i] = 0;
}

void DynamicArray::append(int data) {
    if (this->length == this->size) this->grow();

    this->arr[length] = data;
    this->length++;
}

void DynamicArray::insert(int index, int data) {
    if (this->length == this->size) this->grow();

    for (int i = this->length; i > index; --i) 
        this->arr[i] = this->arr[i - 1];
    this->arr[index] = data;
    this->length++;
}

void DynamicArray::grow() {
    int* temp = new int[this->size * 2];
    for (int i = 0; i < this->size * 2; ++i) {
        if (i < this->length)
            temp[i] = this->arr[i];
        else 
            temp[i] = 0;
    }

    delete[] this->arr;
    this->arr = temp;
    this->size *= 2;
}

void DynamicArray::print() {
    for (int i = 0; i < this->size; ++i)
        cout << this->arr[i] << " ";
    cout << endl;
}

int DynamicArray::pop() {
    this->length--;
    int temp = this->arr[this->length];
    this->arr[this->length] = 0;

    return temp;
}

int DynamicArray::remove(int index) {
    int temp = this->arr[index];
    for (int i = index; i < this->length; ++i) 
        this->arr[i] = this->arr[i + 1];
    this->arr[this->length] = 0;
    this->length--;

    return temp;
}

void DynamicArray::shrink() {
    int* temp = new int[this->length];
    for (int i = 0; i < this->length; ++i) 
        temp[i] = this->arr[i];

    delete[] this->arr;
    this->arr = temp;
    this->size = this->length;
}
