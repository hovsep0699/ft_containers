/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:26:57 by mleblanc          #+#    #+#             */
/*   Updated: 2022/11/21 07:13:47 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_prelude.hpp"

void set_test_erase_range()
{
    SETUP_ARRAYS();

    {
        strset m;

        m.erase(m.begin(), m.end());

        PRINT_ALL(m);

        m.insert(str_arr, str_arr + str_size);

        m.erase(m.begin(), m.end());

        PRINT_ALL(m);
    }

    {
        intset m(int_arr, int_arr + int_size);

        intset::iterator it(m.begin());
        intset::iterator end(it);

        NAMESPACE::advance(end, 1);

        m.erase(it, end);

        PRINT_ALL(m);

        it = m.begin();
        end = it;
        NAMESPACE::advance(it, 24);
        NAMESPACE::advance(end, 30);

        m.erase(it, end);

        PRINT_ALL(m);

        it = m.begin();
        end = it;
        NAMESPACE::advance(it, 34);
        NAMESPACE::advance(end, 55);

        m.erase(it, end);

        PRINT_ALL(m);

        it = m.begin();
        end = it;
        NAMESPACE::advance(end, 1);

        m.erase(it, end);

        PRINT_ALL(m);

        m.erase(m.begin(), m.end());

        PRINT_ALL(m);
    }
}

MAIN(set_test_erase_range)
