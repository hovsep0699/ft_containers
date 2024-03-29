/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:04:03 by mleblanc          #+#    #+#             */
/*   Updated: 2022/11/21 04:40:24 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_erase()
{
    SETUP_ARRAYS();

    {
        intmap m(intstr_arr, intstr_arr + 25);

        intmap::iterator it = m.begin();

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

MAIN(map_test_erase)
