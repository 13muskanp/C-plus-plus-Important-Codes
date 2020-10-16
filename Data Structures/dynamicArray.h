#pragma once

class DynamicArray {
    public:
        DynamicArray();
        void append(int data);
        void insert(int index, int data);
        void print();
        int pop();
        int remove(int index);
        void shrink();

    private:
        int* arr;
        int length;
        int size;
        void grow();
};
