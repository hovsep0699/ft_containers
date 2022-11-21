/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:24:41 by mleblanc          #+#    #+#             */
/*   Updated: 2022/11/21 07:13:25 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_prelude.hpp"

void set_test_erase()
{
    SETUP_ARRAYS();

    {
        intset m(int_arr, int_arr + 25);

        intset::iterator it = m.begin();

        m.erase(it);

        PRINT_ALL(m);

        it = m.begin();

        NAMESPACE::advance(it, 21);

        m.erase(it);

        PRINT_ALL(m);

        it = m.end();

        NAMESPACE::advance(it, -10);

        m.erase(it);

        PRINT_ALL(m);

        it = m.end();

        NAMESPACE::advance(it, -3);

        m.erase(it);

        PRINT_ALL(m);

        it = m.end();

        NAMESPACE::advance(it, -1);

        m.erase(it);

        PRINT_ALL(m);

        it = m.begin();

        NAMESPACE::advance(it, 1);

        m.erase(it);

        PRINT_ALL(m);

        for (it = m.begin(); it != m.end(); it = m.begin()) {
            m.erase(it);
            PRINT_ALL(m);
        }
    }
}

MAIN(set_test_erase)
