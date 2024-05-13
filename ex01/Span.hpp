#ifndef SPAN_HPP
# define SPAN_HPP

# include<iostream>
# include<algorithm>
# include<exception>
# include<vector>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	printVector();
		void	binaryAdd(int start, int end, int n);

		class FullContainerException: public std::exception
		{
			public:
				virtual const char *what() const throw() override;
		};

		class NumberAlreadyStoredException: public std::exception
		{
			public:
				virtual const char *what() const throw() override;
		};

	private:
		std::vector<int>	_V;
		unsigned int	_shortest_span;
		unsigned int	_longest_span;
		unsigned int	_len;
		unsigned int	_N;
};

#endif