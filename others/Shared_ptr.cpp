#include <atomic>
#include <iostream>

template<typename T>
class SharedPtr {
private:
    T* ptr_;               // 原始指针
    std::atomic<int>* ref_count_;  // 引用计数（原子操作，线程安全）
    
public:
    // 1. 默认构造
    SharedPtr() : ptr_(nullptr), ref_count_(nullptr) {}
    
    // 2. 从原始指针构造
    explicit SharedPtr(T* ptr) : ptr_(ptr), ref_count_(nullptr) {
        if (ptr_) {
            ref_count_ = new std::atomic<int>(1);
        }
    }
    
    // 3. 拷贝构造（增加引用计数）
    SharedPtr(const SharedPtr& other) 
        : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        if (ref_count_) {
            (*ref_count_)++;
        }
    }
    
    // 4. 移动构造（转移所有权，不增加计数）
    SharedPtr(SharedPtr&& other) noexcept
        : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        other.ptr_ = nullptr;
        other.ref_count_ = nullptr;
    }
    
    // 5. 析构函数（减少引用计数，必要时释放资源）
    ~SharedPtr() {
        release();
    }
    
    // 6. 拷贝赋值
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();                    // 释放当前资源
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            if (ref_count_) {
                (*ref_count_)++;
            }
        }
        return *this;
    }
    
    // 7. 移动赋值
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();                    // 释放当前资源
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            other.ptr_ = nullptr;
            other.ref_count_ = nullptr;
        }
        return *this;
    }
    
    // 8. 解引用操作符
    T& operator*() const {
        return *ptr_;
    }
    
    // 9. 箭头操作符
    T* operator->() const {
        return ptr_;
    }
    
    // 10. 获取原始指针
    T* get() const {
        return ptr_;
    }
    
    // 11. 获取引用计数
    int use_count() const {
        return ref_count_ ? ref_count_->load() : 0;
    }
    
    // 12. 检查是否唯一
    bool unique() const {
        return use_count() == 1;
    }
    
    // 13. 重置指针
    void reset(T* ptr = nullptr) {
        release();                        // 释放当前资源
        ptr_ = ptr;
        if (ptr_) {
            ref_count_ = new std::atomic<int>(1);
        } else {
            ref_count_ = nullptr;
        }
    }
    
    // 14. 布尔转换（判断是否非空）
    explicit operator bool() const {
        return ptr_ != nullptr;
    }
    
private:
    void release() {
        if (ref_count_) {
            if (--(*ref_count_) == 0) {
                delete ptr_;
                delete ref_count_;
            }
            ptr_ = nullptr;
            ref_count_ = nullptr;
        }
    }
};