#include "Serializer.hpp"
#include <iostream>

int main() {
	Data myData;
	myData.id = 42;
	myData.name = "Test Data";
	myData.value = 3.14f;

	std::cout << "Original Data Address: " << &myData << std::endl;
	std::cout << "Original Data: " << myData.id << ", " << myData.name << ", " << myData.value << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	Data* deserializedPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized Address: " << deserializedPtr << std::endl;

	if (deserializedPtr == &myData) {
		std::cout << "SUCCESS: Pointers match!" << std::endl;
		std::cout << "Recovered Data: " << deserializedPtr->id << ", " 
				  << deserializedPtr->name << ", " << deserializedPtr->value << std::endl;
	} else {
		std::cout << "FAILURE: Pointers do not match!" << std::endl;
	}

	return 0;
}
