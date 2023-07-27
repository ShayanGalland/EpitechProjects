#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

template<typename T>
void swap(T &a, T &b)
{
    T ret = a;
    a = b;
    b = ret;
}

template<typename C>
C min(C a, C b)
{
    if (a < b)
        return a;
    else
        return b;
}

template<typename Z>
Z max(Z a, Z b)
{
    if (a < b)
        return b;
    else
        return a;
}

template<typename U>
U clamp(U clp, U b, U c)
{
    if (b < c) {
        if (clp < b) return b;
        if (c < clp) return c;
        return clp;
    } else {
        if (c < clp) return c;
        if (clp < b) return b;
        return clp;
    }
}

#endif