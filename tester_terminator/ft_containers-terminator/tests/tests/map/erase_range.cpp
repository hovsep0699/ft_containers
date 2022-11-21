/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:23:58 by mleblanc          #+#    #+#             */
/*   Updated: 2022/11/21 04:16:59 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_erase_range()
{
    SETUP_ARRAYS();

    {
        strmap m;

        m.erase(m.begin(), m.end());

        PRINT_ALL(m);

        m.insert(strstr_arr, strstr_arr + strstr_size);

        m.erase(m.begin(), m.end());

        PRINT_ALL(m);
    }

    {
        intmap m(intstr_arr, intstr_arr + intstr_size);

        intmap::iterator it(m.begin());
        intmap::iterator end(it);

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

MAIN(map_test_erase_range)
