#ifndef PRG_7LABA_CIRC_BUFF_CIRCULAR_BUFFER_H
#define PRG_7LABA_CIRC_BUFF_CIRCULAR_BUFFER_H

#include <iostream>
using namespace std;


template <typename T>
class CircularBuffer {
private:
    T *m_buffer;
    int m_indHEAD;
    int m_indTAIL;
    int m_current_size;
    int m_capacity;

public:
    CircularBuffer(const int capac) {
        m_buffer = new T[capac];
        m_indHEAD = 0;
        m_indTAIL = 0;
        m_current_size = 0;
        m_capacity = capac;

    }

    ~CircularBuffer() {
        delete[] this->m_buffer;
    }


    void push_back(const T value) {
        m_indTAIL = (m_indTAIL - 1 + m_capacity) % m_capacity;
        m_buffer[m_indTAIL] = value;

        if(isFull() == 0)
            m_current_size++;
    }

    void pop_back() {
        if(isEmpty()) {
            cerr << "Buffer is empty, do not delete the element\n";
            return;
        }

        m_buffer[m_indTAIL] = 0;
        m_indTAIL = (m_indTAIL + 1) % m_capacity;
        m_current_size--;
    }


    void push_front(const T value) {
        m_buffer[m_indHEAD] = value;
        m_indHEAD = (m_indHEAD + 1) % m_capacity;

        if(isFull() == 0)
            m_current_size++;
    }

    void pop_front() {
        if(isEmpty()) {
            cerr << "Buffer is empty, do not delete the element\n";
            return;
        }

        m_indHEAD = (m_indHEAD - 1) % m_capacity;
        m_buffer[m_indHEAD] = 0;
        m_current_size--;
    }



    class Iterator: public iterator<random_access_iterator_tag, T> {
    private:
        T *ptr;

    public:
        Iterator(T *p): ptr(p) {}


        T& operator* () const {
            return *ptr;
        }

        Iterator& operator++ () {
            ptr++;
            return *this;
        }

        T operator-> () const {
            return ptr;
        }

        Iterator& operator+=(int other) {
            ptr += other;
            return *this;
        }

        Iterator& operator-= (int other) {
            ptr -= other;
            return *this;
        }

        Iterator& operator-- () {
            ptr--;
            return *this;
        }

        Iterator operator- (const int other) const {
            return Iterator(ptr - other);
        }

        Iterator operator+ (const int other) const {
            return Iterator(ptr + other);
        }

        bool operator< (const Iterator &other) const {
            return ptr < other.ptr;
        }

        bool operator> (const Iterator &other) const {
            return ptr > other.ptr;
        }


        bool operator<= (const Iterator &other) const {
            return ptr <= other.ptr;
        }

        bool operator>= (const Iterator &other) const {
            return ptr >= other.ptr;
        }

        size_t operator- (const Iterator &other) const {
            return ptr - other.ptr;
        }

        bool operator!= (const Iterator &other) const {
            return ptr != other.ptr;
        }

        bool operator== (const Iterator &other) const {
            return ptr == other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(m_buffer);
    }

    Iterator end() {
        return Iterator(&m_buffer[m_capacity]);
    }



    void insert(const T element, Iterator position) {
        Iterator start = this->begin();

        while(start != position && start != this->end()) {
            ++start;
        }

        *start = element;
    }


    void erase(Iterator position) {
        if(m_current_size == 0) {
            cerr << "buffer is empty";
            return;
        }


        Iterator start = this->begin();
        while(start != position && start != this->end()) {
            ++start;
        }

        if(start != this->end())
            *start = 0;
    }


    T vievHead() const {
        if(m_indHEAD == 0)
            return m_buffer[m_indHEAD];
        else
            return m_buffer[(m_indHEAD - 1) % m_capacity];
    }

    T vievTail() const {
        if(m_indTAIL == 0)
            return m_buffer[(m_indTAIL - 1 + m_capacity) % m_capacity];
        else
            return m_buffer[m_indTAIL % m_capacity];
    }



    T& operator[] (const int indexElement) {
        return  m_buffer[indexElement];
    }


    void resize(const int new_capac) {
        if(new_capac < m_current_size) {
            cerr << "new capacity smaller current size\n";
            return;
        }


        T *new_buffer = new T[new_capac];
        for(int i = 0; i < new_capac; i++) {
            new_buffer[i] = 0;
        }

        bool flag_break = 0;
        m_indHEAD = 0;

        for(int i = 0; i < m_capacity; i++) {
            if(m_buffer[i] != 0)
                new_buffer[i] = m_buffer[m_indHEAD++];
            else {
                flag_break = 1;
                break;
            }
        }

        if(flag_break == 1) {
            m_indTAIL = new_capac-1;
            for(int i = m_capacity-1; i >= 0; i--) {
                if(m_buffer[i] != 0)
                    new_buffer[m_indTAIL--] = m_buffer[i];
                else {
                    m_indTAIL++;
                    break;
                }
            }
        }

        if(flag_break == 0) {
            m_indHEAD = 0;
            m_indTAIL = 0;
        }

        delete[] m_buffer;
        m_buffer = new_buffer;
        m_capacity = new_capac;
    }



    void outputBuffer() const {
        for(int i = 0; i < m_capacity; i++) {
            cout << m_buffer[i] << " ";
        }
        cout << "\n";
    }



    bool isFull() const {
        return m_current_size == m_capacity;
    }

    bool isEmpty() const {
        return m_current_size == 0;
    }
};
#endif