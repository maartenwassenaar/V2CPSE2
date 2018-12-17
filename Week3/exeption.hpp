#ifndef _UNKNOWN_HPP
#define _UNKNOWN_HPP

#include <exception>
#include <iostream>

class unknown_color : public std::exception {
public:
	unknown_color(const std::string & name) :
		s{ std::string{ "unknown colcor [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_name : public std::exception {
public:
	unknown_name(const std::string & name) :
		s{ std::string{ "unknown name [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_pos : public std::exception {
public:
	unknown_pos(const std::string & name) :
		s{ std::string{ "unknown posistion [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_picture : public std::exception {
public:
	unknown_picture(const std::string & name) :
		s{ std::string{ "unknown picture [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class invalid_position : public std::exception {
public:
	invalid_position(const char & name) :
		s{ std::string{ "invalid_position [" } +name + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class end_of_file : public std::exception {
public:
	end_of_file() :
		s{ std::string{ "end_of_file" }}
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

#endif