#include <iostream>
#include <cstdarg>
#include <cmath>
#include <vector>


template<typename T>
T get_polinom_res(T x, int count, ...) {
	T sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		double c = va_arg(args, double);
		sum += (c * pow(x, i));
	}
	va_end(args);
	return sum;
}


template<typename T>
std::vector<T> get_polinom(int count, ...) {
	std::vector<T> vec;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		double c = va_arg(args, double);
		vec.push_back(c);
	}
	va_end(args);
	return vec;
}


template<typename T>
T get_result(std::vector<T> v, T x) {
	T sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += (v[i]*pow(x, i));
	}
	return sum;
}


template<typename T>
bool test(T res1, T res2) {
	std::cout << res1 << ' ' << res2 << '\t';
	if (res1 == res2) {
		std::cout << "OK" << std::endl;
		return true;
	}
	std::cout << "Error!" << std::endl;
	return false;
}

int main() {
	
	test(get_polinom_res(2., 3, 3., 2., 1.), get_result(get_polinom<double>(3, 3., 2., 1.), 2.));
	std::cout << std::endl;
	test(get_polinom_res(3., 4, 1.3, 2.2, -1.1, 2.), get_result(get_polinom<double>(4, 1.3, 2.2, -1.1, 2.), 3.));
	std::cout << std::endl;
	
	system("pause");
	return 0;
}