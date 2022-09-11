#include <algorithm>
#include <utility>

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
    template <typename U>
    friend class smart_ptr;

    explicit smart_ptr(T *ptr = nullptr) : ptr_(ptr)
    {
        if (ptr)
        {
            shared_count_ = new shared_count();
        }
    }

    ~smart_ptr()
    {
        if (ptr_ && !shared_count_->reduce_count())
        {
            delete ptr_;
            delete shared_count_;
        }
    }

    smart_ptr(const smart_ptr &other)
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    template <typename U>
    smart_ptr(const smart_ptr<U> &other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    template <typename U>
    smart_ptr(smart_ptr<U> &&other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }

    template <typename U>
    smart_ptr(const smart_ptr<U> &other, T *ptr) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    T *get() const noexcept
    {
        return ptr_;
    }

    T &operator*() const noexcept
    {
        return *ptr_;
    }

    T *operator->() const noexcept
    {
        return ptr_;
    }

    smart_ptr &operator=(smart_ptr rhs) noexcept
    {
        rhs.swap(*this);
        return *this;
    }

    operator bool() const noexcept
    {
        return ptr_;
    }

    long use_count() const noexcept
    {
        if (ptr_)
        {
            return shared_count_->get_count();
        }
        else
        {
            return 0;
        }
    }

    void swap(smart_ptr &rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr);
        swap(shared_count_, rhs.shared_count_);
    }
};

template <typename T, typename U>
smart_ptr<T> static_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = static_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr);
}
template <typename T, typename U>
smart_ptr<T> reinterpret_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = reinterpret_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr);
}
template <typename T, typename U>
smart_ptr<T> const_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = const_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr);
}
template <typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = dynamic_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr);
}
