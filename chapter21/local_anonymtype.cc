enum
{
    V1,
    V2,
    V3
};

template <typename T>
void fun(T &&t)
{
    T var(t);
}

void definer()
{
    struct Local
    {
        double  dVar;
        int     iVar;
    };
    Local local;            // using a local type

    fun(local);             // OK: T is 'Local'
}

int main(int argc, char*argv[])
{
    fun(V1); // V1 has anonymous type
}
