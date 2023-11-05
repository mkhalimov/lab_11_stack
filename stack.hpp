#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
#include <vector>


template<typename T>
class stack {   
private:
    std::vector<T> elems;

public:
    bool empty() const {
        return elems.empty();
    }

	size_t size() const{
		return elems.size();	
	}

    T top() {
        if (elems.empty()) {
            throw std::out_of_range("Stack::top(): empty stack");
        }
        return elems.back();
    }

    void push(const T& elem) {
        elems.push_back(elem);
    }

    void pop() {
        if (elems.empty()) {
            throw std::out_of_range("Stack::pop(): empty stack");
        }
        elems.pop_back();
    }

    class Iterator {
    private:
        typename std::vector<T>::reverse_iterator it;

    public:
        using value_type = typename std::vector<T>::value_type;
        using reference = typename std::vector<T>::reference;
        using pointer = typename std::vector<T>::pointer;
        using difference_type = typename std::vector<T>::difference_type;
        using iterator_category = std::forward_iterator_tag;

        Iterator(typename std::vector<T>::reverse_iterator rit) : it(rit) {}

        Iterator& operator++() {
            ++it;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp(*this);
            operator++();
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return it == other.it;
        }

        bool operator!=(const Iterator& other) const {
            return it != other.it;
        }

        reference operator*() {
            return *it;
        }
    };

    Iterator begin() {
        return Iterator(elems.rbegin());
    }

    Iterator end() {
        return Iterator(elems.rend());
    }
};

#endif // STACK_HPP