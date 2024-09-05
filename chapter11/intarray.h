    #include <cstddef>

    class IntArray
    {
        size_t d_size;
        int     *d_data;

         public:
            IntArray(size_t size = 1);
            IntArray(IntArray const &other);
            ~IntArray();
            IntArray &operator=(IntArray const &other);

                                                // overloaded index operators:
            int &operator[](size_t index);              // first
            int const &operator[](size_t index) const;  // second

            void swap(IntArray &other);         // trivial

        private:
            void boundary(size_t index) const;
            int &operatorIndex(size_t index) const;
    };
