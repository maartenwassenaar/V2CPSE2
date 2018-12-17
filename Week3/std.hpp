

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) { throw end_of_file(); }
	if (c != '(') { throw invalid_position(c); }

	if (!(input >> rhs.x)) { . . . }

	if (!(input >> c)) { . . . }
	. . .
		if (!(input >> rhs.y)) { . . . }

	if (!(input >> c)) { . . . }
	if (c != ')') { throw invalid_position(c); }

	return input;
}
