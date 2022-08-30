#include <algorithm>

class shared_count
{
private:
    long count_;

public:
    shared_count() : count_(1){};

    void add_count()
    {
        ++count_;
    }

    long reduce_count()
    {
        return --count_;
    }

    long get_count()
    {
        return count_;
    }
};

template <typename T>
class smart_ptr
{
private:
    T *ptr_;
    shared_count *shared_count_;

public:
    explicit smart_ptr(T *ptr = nullptr) : ptr_(ptr)
    {
        if (ptr)
        {
            shared_count_ = new shared_count();
        }
    }

    smart_ptr(const smart_ptr& other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    smart_ptr(smart_ptr&& other)
    {
        ptr_ = other.release();
    }

    template <typename U>
    smart_ptr(smart_ptr<U> &&other)
    {
        ptr_ = other.release();
    }

    ~smart_ptr()
    {
        if (ptr_ && !shared_count_->reduce_count())
        {
            delete ptr_;
            delete shared_count_;
        }
    }

    T *get() const
    {
        return ptr_;
    }

    T &operator*() const
    {
        return *ptr_;
    }

    T *operator->() const
    {
        return ptr_;
    }

    smart_ptr &operator=(smart_ptr rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    operator bool() const
    {
        return ptr_;
    }

    T *release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(smart_ptr &rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr);
        swap(shared_count_, rhs.shared_count_);
    }
};
