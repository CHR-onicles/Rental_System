#pragma once

class MissingFileException : std::exception {
public:
	MissingFileException()noexcept = default;
	~MissingFileException() = default;

	const char* what()const noexcept {
		return "Error opening file!";
	}
};