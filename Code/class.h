template<typename T>  //Generalize our vector-of-doubles type to a vector-of-anything type
class vector{
    public:
        vector(int s);
        ~vector(){delete[] elem;}
        
        //Suppressing operation with delete

        //Copy constructor
        vector(const vector&) = delete;
        //Copy Assignment
        vector& operator=(const vector&) = delete;
        
        //Move Constructopr
        vector(vector&&) = delete;
        //Move Assignement
        vector& operator=(vector&&) = delete;

        T& operator[](int i);
        const T& operator[](int i) const;

        int size();
        
    private:
        T* elem;
        int sz;
};

template<typename T>
vector<T>::vector(int s)
{
    if(s<0) throw Negative_size{};
    elem = new T[s];
    sz = s;
}

template<typename T>
const T& vector::operator[](int i) const
{
    if(i<0 || size()<=i)
        throw out_of_range{"vector::operator[]"};
    return elem[i];
}
//Copy Constructor
vector::vector(const vector& a):elem{new double[sz]}, sz{a.sz}
{
    for(int i=0; i!=sz; ++i)
        elem[i]=a.elem[i];
}

//Copy Assignement
vector& vector::operator=(const vector& a)
{
    double* p = new double[a.sz];
    for(int i=0;i!=sz;++i)
        p[i]=a.elem[i];
    delete[] elem; //Delete old element
    elem = p;
    sz = a.sz;
    return *this;
}

//Move Constructor
vector::vector(vector&& a):elem{a.elem}, sz{a.sz}
{
    a.elem = nullptr;
    a.sz = 0;
}