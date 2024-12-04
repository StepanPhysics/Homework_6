#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <cstddef>   
#include <stdexcept> 

template<typename T>
class SimpleList {
public:
    SimpleList();
    ~SimpleList();

    void push_back(const T& value);
    void insert(size_t index, const T& value);
    void remove(size_t index);
    T& operator[](size_t index);
    size_t size() const;

private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t m_size;

    Node* get_node(size_t index);
};

template<typename T>
SimpleList<T>::SimpleList() : head(nullptr), tail(nullptr), m_size(0) {}

template<typename T>
SimpleList<T>::~SimpleList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void SimpleList<T>::push_back(const T& value) {
    Node* node = new Node(value);
    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    ++m_size;
}

template<typename T>
void SimpleList<T>::insert(size_t index, const T& value) {
    if (index > m_size) {
        throw std::out_of_range("Index out of range");
    }

    Node* node = new Node(value);

    if (index == 0) {
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (m_size == 0) tail = node;
    }
    else if (index == m_size) {
        push_back(value);
        return;
    }
    else {
        Node* current = get_node(index);
        node->next = current;
        node->prev = current->prev;
        if (current->prev) current->prev->next = node;
        current->prev = node;
    }

    ++m_size;
}

template<typename T>
void SimpleList<T>::remove(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    Node* node_to_remove = get_node(index);

    if (node_to_remove->prev) {
        node_to_remove->prev->next = node_to_remove->next;
    }
    else {
        head = node_to_remove->next;
    }

    if (node_to_remove->next) {
        node_to_remove->next->prev = node_to_remove->prev;
    }
    else {
        tail = node_to_remove->prev;
    }

    delete node_to_remove;
    --m_size;
}

template<typename T>
T& SimpleList<T>::operator[](size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return get_node(index)->data;
}

template<typename T>
size_t SimpleList<T>::size() const {
    return m_size;
}

template<typename T>
typename SimpleList<T>::Node* SimpleList<T>::get_node(size_t index) {
    Node* current = head;
    size_t currentIndex = 0;
    while (currentIndex < index) {
        current = current->next;
        ++currentIndex;
    }
    return current;
}

#endif 
