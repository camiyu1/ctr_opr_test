#include <iostream>
#include <vector>

class TENSOR {
 public:
    TENSOR() {
        std::cout << "Default constructor called\n";
    }
    ~TENSOR() {
        std::cout << "Default destructor called\n";
    }
    TENSOR(const TENSOR& other) {
        val = other.val;
        std::cout << "Copy constructor called\n";
    }
#if 1
    TENSOR& operator=(const TENSOR& other) {
        if (this == &other) return *this;
        this->val = other.val;
        std::cout << "Assigned operator called\n";
        return *this;
    }
#else
    TENSOR operator=(TENSOR other) {
        if (this == &other) return *this;
        this->val = other.val;
        std::cout << "Copy operator called\n";
        return *this;
    }
#endif
    std::vector<int> val;
};

TENSOR modification(const TENSOR& tensor) {
    TENSOR result = tensor;
    return result;
}

int main() {
    TENSOR test;
    test.val.push_back(5);
    TENSOR abc = modification(test);
}
