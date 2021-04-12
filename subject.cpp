// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "subject.h"
#include <math.h>

namespace corsim
{

Subject::Subject(int x, int y, int radius, bool infected, MovementStrategy& strategy)
{
    this->_x = x;
    this->_y = y;
    this->_radius = radius;
    this->_infected = infected;
    this->_movementStrategy = &strategy;
}

double Subject::x()
{
    return this->_x;
}

double Subject::y()
{
    return this->_y;
}

void Subject::set_x(double x)
{
    this->_x = x;
}

void Subject::set_y(double y)
{
    this->_y = y;
}

double Subject::dx()
{
    return this->_movementStrategy->get_dx();
}

double Subject::dy()
{
    return this->_movementStrategy->get_dy();
}

void Subject::set_dx(double dx)
{
    this->_movementStrategy->set_dx(dx);
}

void Subject::set_dy(double dy)
{
    this->_movementStrategy->set_dy(dy);
}

int Subject::radius()
{
    return this->_radius;
}

bool Subject::infected()
{
    return this->_infected;
}

void Subject::infect()
{
    this->_infected = true;
}

double Subject::angle()
{
    return atan2(dy(),dx());
}

double Subject::speed()
{
    return sqrt(dx() * dx() + dy() * dy());
}

}