#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <list>
#ifdef FT_CONTAINER
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#define NAMESPACE ft
#else
#include <vector>
#include <map>
#include <stack>
#define NAMESPACE std
#endif

void	vector_test();
void	stack_test();
void	map_test();
