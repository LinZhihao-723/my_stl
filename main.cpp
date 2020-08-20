#include <iostream>
#include "containers.h"

int main() {
    vector<int> vec(3, 0);

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    vec.pop_back();
    vec.resize(8, 0);

    vector<int> new_vec(vec);

    new_vec.erase(5);

    for(int i = 0; i < new_vec.size(); ++ i) {
        std::cout << new_vec[i] << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < vec.size(); ++ i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
