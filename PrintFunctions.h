#pragma once
#include <iostream>
#include <string>

template<typename T>
inline void Print(T m) {
	std::cout << m;
}

template<typename T>
inline void Println(T m) {
	std::cout << m << std::endl;
}

template<typename T>
inline void Println(const std::string message, T m) {
	std::cout << message << m << std::endl;
}

inline void PrintColor(Color color) {
	std::cout << "r: " << color.r << " g: " << color.g << " b: " << color.b << " a: " << color.a << std::endl;
}