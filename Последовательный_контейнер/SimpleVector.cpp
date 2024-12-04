#include <iostream>
#include <stdexcept>

template <typename T>
class SimpleVector {
public:
    SimpleVector()
        : m_size(0), m_capacity(1), m_data(new T[m_capacity]) {}

    ~SimpleVector() {
        delete[] m_data;
    }

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            reserve(m_capacity * 2);
        }
        m_data[m_size++] = value;
    }

    void insert(size_t index, const T& value) {
        if (index > m_size) {
            throw std::out_of_range("Index out of range");
        }
        if (m_size == m_capacity) {
            reserve(m_capacity * 2); 
        }
        for (size_t i = m_size; i > index; --i) {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = value;
        m_size++;
    }

    void erase(size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < m_size - 1; ++i) {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
    }

    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    size_t size() const {
        return m_size;
    }

    void print() const {
        for (size_t i = 0; i < m_size; ++i) {
            std::cout << m_data[i];
            if (i < m_size - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

private:
    void reserve(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

    size_t m_size;
    size_t m_capacity;
    T* m_data;
};

int main() {
    SimpleVector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    std::cout << "Initial elements: ";
    vec.print();

    std::cout << "Size: " << vec.size() << std::endl;

    vec.erase(2); 
    vec.erase(3); 
    vec.erase(4); 


    std::cout << "After deletions: ";
    vec.print();


    vec.insert(0, 10);
    std::cout << "After adding 10 at the start: ";
    vec.print();

    vec.insert(vec.size() / 2, 20);
    std::cout << "After adding 20 in the middle: ";
    vec.print();

    vec.push_back(30);
    std::cout << "After adding 30 at the end: ";
    vec.print();

    return 0;
}