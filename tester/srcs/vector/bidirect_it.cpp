#include "common.hpp"
#include "set.hpp"

#define TESTED_TYPE int

int		main(void)
{
	std::set<TESTED_TYPE> lst;
	TESTED_NAMESPACE::set<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.insert(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}
