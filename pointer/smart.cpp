template <typename T>
class smart_ptr
{
private:
    T *ptr_;

public:
    explicit smart_ptr(T *ptr = nullptr) : prt_(ptr) {}

    template <typename U>
    smart_ptr(smart_ptr<U> &&other)
    {
        ptr_ = other.release();
    }

    smart_ptr(smart_ptr &&other)
    {
        ptr_ = other.release();
    }

    ~smart_ptr()
    {
        delete ptr_;
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
    }
};
