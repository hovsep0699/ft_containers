/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_comp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:35:21 by mleblanc          #+#    #+#             */
/*   Updated: 2022/11/21 05:01:22 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_value_comp()
{
    SETUP_ARRAYS();

    {
        strmap m(strstr_arr, strstr_arr + strstr_size);

        strmap::iterator it = m.begin();
        strmap::const_iterator cit = m.begin();
        strmap::value_compare comp = m.value_comp();

        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(cit, 5);
        NAMESPACE::advance(it, 14);

        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(it, 7);
        NAMESPACE::advance(cit, 3);

        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(it, -3);
        NAMESPACE::advance(cit, 12);

        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(it, -1);
        NAMESPACE::advance(cit, 1);

        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
    }

    {
        intmap m(intstr_arr, intstr_arr + intstr_size);

        intmap::iterator it = m.begin();
        intmap::iterator it2 = m.begin();
        intmap::value_compare comp = m.value_comp();

        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(it, 14);
        NAMESPACE::advance(it2, 5);

        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(it, 7);
        NAMESPACE::advance(it2, 3);

        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(it, -3);
        NAMESPACE::advance(it2, 12);

        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }

        NAMESPACE::advance(it, -1);
        NAMESPACE::advance(it2, 1);

        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
    }
}

MAIN(map_test_value_comp)
