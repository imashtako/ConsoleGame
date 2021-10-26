#pragma once

template<typename Base, typename T>
bool instanceOf(const T* a) {
	return std::is_base_of<Base, T>::value;
}
