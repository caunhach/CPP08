#include "Span.hpp"

Span::Span() : _N(0), _len(0), _shortest_span(0), _longest_span(0) { }

Span::Span(unsigned int N) : _N(N), _len(0), _shortest_span(0), _longest_span(0) { }

Span::Span(const Span &src) : _V(src._V), _len(src._len), _N(src._N) { }

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_V = src._V;
		_len = src._len;
		_N = src._N;
	}
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (_len == _N)
		throw FullContainerException();
	auto start = _V.begin();
	auto end = _V.end();
	if (_len == 0)
		_V.insert(start, n);
	else
		binaryAdd(0, _len, n);
	_len++;
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_len + std::distance(begin, end) > _N)
		throw FullContainerException();

	for (auto it = begin; it != end; ++it)
		addNumber(*it);
}

void	Span::printVector()
{
	for (auto it = _V.begin(); it != _V.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "longest span: " << _longest_span << std::endl;
	std::cout << "shortest span: " << _shortest_span << std::endl;
}

void	Span::binaryAdd(int start, int end, int n)
{
	int	mid = (start + end) / 2;
	auto tmp = _V.begin() + mid;

	if (start < end) {
		if (*tmp == n)
			throw NumberAlreadyStoredException();
		else if (n < _V[start]) {
			_V.insert(_V.begin(), n);
			_longest_span = _V[_len] - n > _longest_span ? _V[_len] - n : _longest_span;
			if (_len == 1)
				_shortest_span = _V[1] - _V[0];
			else
				_shortest_span = _V[1] - _V[0] < _shortest_span? _V[1] - _V[0] : _shortest_span;
		}
		else if (n > _V[end - 1]) {
			_V.insert(_V.begin() + end, n);
			_longest_span = n - *_V.begin() > _longest_span ? n - *_V.begin() : _longest_span;
			if (_len == 1)
				_shortest_span = n - _V[end - 1];
			else
				_shortest_span = n - _V[end - 1] < _shortest_span? n - _V[end - 1] : _shortest_span;
		}
		else if (n < *tmp)
			binaryAdd(start, mid, n);
		else if (*tmp < n)
			binaryAdd(mid, end, n);
	}
}

const char	*Span::FullContainerException::what() const throw()
{
	return ("Container is Full");
}

const char	*Span::NumberAlreadyStoredException::what() const throw()
{
	return ("Number is Already Existed");
}