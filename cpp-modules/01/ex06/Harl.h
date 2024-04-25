/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:00:43 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 03:00:43 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

#include "Harl.hpp"

enum string_code {
    debugc,
    infoc,
    warningc,
    errorc,
    NO_LEVEL
};

string_code hashHit(std::string level) {
    if (level.compare("debug") == 0) return debugc;
    if (level.compare("info") == 0) return infoc;
    if (level.compare("warning") == 0) return warningc;
    if (level.compare("error") == 0) return errorc;
    return (NO_LEVEL);
}

#endif