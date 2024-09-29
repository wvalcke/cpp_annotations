    #ifndef FATAL_H_
    #define FATAL_H_

    #include "exception.h"

    class Fatal: public Exception
    {
        public:
            Fatal(std::string  const &reason);
        private:
            void action() const override;
    };

    inline Fatal::Fatal(std::string  const &reason)
    :
        Exception(reason)
    {}

    inline void Fatal::action() const
    {
        std::cout << "Fatal::action() terminates" << '\n';
        std::terminate();
    }

    #endif
