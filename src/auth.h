/*
 *  Hans - IP over ICMP
 *  Copyright (C) 2009 Friedrich Schöller <hans@schoeller.se>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef AUTH_H
#define AUTH_H

#include <vector>
#include <string>
#include <string.h>
#include <stdint.h>

class Auth
{
public:
    typedef std::vector<char> Challenge;

    struct Response
    {
        uint32_t data[5];
        bool operator==(const Response &other) const { return memcmp(this, &other, sizeof(Response)) == 0; }
    };

    Auth(const std::string &passphrase);

    Challenge generateChallenge(int length) const;
    Response getResponse(const Challenge &challenge) const;

protected:
    std::string passphrase;
    std::string challenge;
};

#endif
