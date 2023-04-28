#include <cstdarg>

using namespace std;

inline void pri_fenge() {
	cout << "--------------------\n";
}

template <typename T>
inline void print_st(const T &t)
{
	cout << t << "\n";
	pri_fenge();
}

template <typename T, typename...Args>
inline void print_st(const T &t, const Args&...rest)
{
	cout << t << " ";
	print_st(rest...);     
}
