#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

std::vector<int> search_subsequence(std::vector<int> numbers);

int main(){
	std::vector<int> numbers; //массив из целых чисел
	std::string line;
	std::getline(std::cin, line); //считываем строку в line
	std::stringstream ss(line); //создаем поток ss
	int num;
	while (ss >> num){
		numbers.push_back(num); //записываем число в массив
	}
	std::vector<int> sub = search_subsequence(numbers);
	for (int val : sub){ //range-based for loop
		std::cout << val << " "; 
	}
	std::cout << std::endl;
	return 0;
}

std::vector<int> search_subsequence(std::vector<int> numbers){
	if (numbers.empty()){
		return {};
	}
	auto it_cur = numbers.begin(); //текущий итератор  
	auto it_st = it_cur; //начало подпоследовательности
	auto it_end_max = it_cur, it_st_max = it_cur; //границы искомой подпоследовательности
	long long sum = *it_cur; //сумма подпоследовательности
	long long len_max = 1; //максимальная сумма
	long long sum_max = sum; //максимальная длина
	while (it_cur != std::prev(numbers.end())) { // .end() возвращает фиктивный итератор, который стоит после последнего числа и который нельзя разыменовать
		auto it_next = std::next(it_cur); //итератор следующий за текущим итератором
		if (*it_cur < *it_next) { 
			sum += *it_next;	
		}
		else { 
			it_st = it_next;
			sum = *it_next;
		}
		long long len = std::distance(it_st, it_next) + 1; //длина текущей подпоследовательности
		if (len > len_max || (len == len_max && sum > sum_max)){ //приоритет длины
			len_max = len;
			sum_max = sum;
			it_st_max = it_st;
			it_end_max = it_next;
		}
		++it_cur;
	}
	return std::vector<int>(it_st_max, std::next(it_end_max)); //возвращаем ПОДпоследовательность
}
