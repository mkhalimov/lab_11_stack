#include "stack.hpp"
#include <iostream>

int main() {
	// Создаем объект stack1 типа Stack<int>
	stack<int> stack1;
	// Заполняем stack1 числами от 1 до 5
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.push(5);

	// Выводим верхний элемент стека
	std::cout << "Top element of stack1: " << stack1.top() << std::endl;

	// Выводим все элементы стека
	std::cout << "Stack1 elements: ";
	for (stack<int>::Iterator it = stack1.begin(); it != stack1.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// Выводим размер стека
	std::cout << "Stack1  size is " << stack1.size() << std::endl;
	
	// Извлекаем все элементы из stack1 и выводим их на экран
	try {
		while (!stack1.empty()) {
		    std::cout << "Popped element from stack1: " << stack1.top() << std::endl;
		    stack1.pop();
		}

	// Пытаемся получить доступ к верхнему элементу пустого стека
	std::cout << "Trying to access top element of an empty stack" << std::endl;
	stack1.top();
	} catch (std::exception& e) {
		// Выводим сообщение об ошибке
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


	
	return 0;
}