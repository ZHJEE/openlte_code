// Copyright 2021 Ben Wojtowicz
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __PollPDU_H__
#define __PollPDU_H__

#include <array>
#include <cstdint>
#include <vector>

class PollPDU
{
public:
    PollPDU() : present{false} {};
public:
    enum Enum {
        k_p4 = 0,
        k_p8,
        k_p16,
        k_p32,
        k_p64,
        k_p128,
        k_p256,
        k_pInfinity,
    };
    int Pack(std::vector<uint8_t> &bits);
    int Unpack(std::vector<uint8_t> bits);
    int Unpack(std::vector<uint8_t> bits, uint32_t &idx);
    Enum Value() const;
    int SetValue(Enum value);
    int SetValue(std::string value);
    std::string ValueToString(Enum value) const;
    uint64_t NumberOfValues() const;
    std::string ToString(uint32_t indent) const;
    std::string ToStringNoNewLines() const;
    int Clear();
    bool IsPresent() const;
private:
    bool present;
    Enum internal_value;
};

#endif