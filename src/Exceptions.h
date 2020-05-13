#pragma once
#include <iostream>

class MissingFileException : std::exception {
public:
	MissingFileException()noexcept = default;
	~MissingFileException() = default;

	virtual const char* what()const noexcept {
		return "Error opening file!";
	}
};