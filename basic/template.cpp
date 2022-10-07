template <typename T>
T sum(T val)
{
    return val;
}

template <typename T, typename... Params>
T sum(T first, Params... params)
{
    return first + sum(params...);
}

int main(void)
{
    int sum1 = sum(1, 2, 3);
    int sum2 = sum(0);
    int sum3 = sum(1, 1);
}
