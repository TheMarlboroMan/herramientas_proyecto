#ifndef MULTIPLATAFORM_PATCHES_COMPAT_H
#define MULTIPLATAFORM_PATCHES_COMPAT_H

#include <string>

namespace compat
{

#ifdef WINCOMPIL
#include <sstream>

template <typename T> std::string to_string(const T& n)
{
	std::ostringstream stm;
	stm<<n;
	return stm.str();
}
#else
template <typename T> std::string to_string(const T& n)
{
	return std::to_string(n);
}
#endif

}

#endif
