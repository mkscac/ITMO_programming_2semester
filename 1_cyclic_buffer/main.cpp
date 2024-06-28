#include "circular_buffer.h"
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {
    if(strcmp(argv[1], "autotest") == 0) {
        CircularBuffer<int> buffer_1(7);

        buffer_1.push_front(1);
        buffer_1.push_front(2);
        buffer_1.push_front(3);
        buffer_1.push_back(9);
        buffer_1.push_back(8);
        buffer_1.push_back(7);

        cout << "push_front, push_back: ";
        buffer_1.outputBuffer();


        buffer_1.pop_front();
        buffer_1.pop_back();
        cout << "pop_front, pop_back: ";
        buffer_1.outputBuffer();

        cout << "vievHead, vievTail: " << buffer_1.vievHead() << " " << buffer_1.vievTail() << "\n";

        cout << "operator[]: " <<  buffer_1[0] << "\n";

        cout << "begin(), end(): " << *buffer_1.begin() << " " << *(buffer_1.end()-1) << "\n"; /// нельзя разименовывать end по правилам


        cout << "insert element = -12 by iterator: ";
        buffer_1.insert(-12, buffer_1.begin()+2);
        buffer_1.outputBuffer();


        cout << "erase element by iterator: ";
        buffer_1.erase(buffer_1.begin()+2);
        buffer_1.outputBuffer();


        cout << "resize buffer: ";
        buffer_1.resize(12);
        buffer_1.outputBuffer();




        cout << "\nvievHead, vievTail without using push_back:\n";
        CircularBuffer<int> buffer_2(3);
        buffer_2.push_front(10);
        buffer_2.push_front(15);
        buffer_2.push_front(20);
        buffer_2.push_front(30);
        buffer_2.outputBuffer();
        cout << buffer_2.vievHead() << " " << buffer_2.vievTail() << "\n";



        cout << "\nSTL-compatibility, std::sort\n";
        CircularBuffer<int> buffer_3(5);
        buffer_3.push_front(40);
        buffer_3.push_front(31);
        buffer_3.push_front(5);
        buffer_3.push_front(20);
        buffer_3.push_back(50);

        cout << "initial state: ";
        buffer_3.outputBuffer();
        cout << "after sorting: ";
        sort(buffer_3.begin(), buffer_3.end());
        buffer_3.outputBuffer();
    }
    return 0;
}
