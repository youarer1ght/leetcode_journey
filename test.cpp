#include <iostream>

template <typename T>
class MySharedPtr {
public:
    MySharedPtr(T* ptr = nullptr) : m_ptr(ptr), m_refCount(new int(1)) {}

    ~MySharedPtr() {
        release();
    }

    MySharedPtr(const MySharedPtr& other) : m_ptr(other.m_ptr), m_refCount(other.m_refCount) {
        (*m_refCount)++;
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            release();
            m_ptr = other.m_ptr;
            m_refCount = other.m_refCount;
            (*m_refCount)++;
        }
        return *this;
    }

    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

    int use_count() const {
        return *m_refCount;
    }

private:
    void release() {
        (*m_refCount)--;
        if (*m_refCount == 0) {
            delete m_ptr;
            delete m_refCount;
        }
    }

    T* m_ptr;
    int* m_refCount;
};