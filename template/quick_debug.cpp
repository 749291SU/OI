#include <cstdarg>

inline void pri_fenge() {
	std::cout << "--------------------\n";
}

template <typename T>
inline void print_st(const T &t)
{
	std::cout << t << "\n";
	pri_fenge();
}

template <typename T, typename...Args>
inline void print_st(const T &t, const Args&...rest)
{
	std::cout << t << " ";
	print_st(rest...);     
}

inline void print_vec(std::vector<i64>& a) {
	for (int i = 0; i < a.size(); i ++) std::cout << a[i] << " ";
	std::cout << "\n";
}
