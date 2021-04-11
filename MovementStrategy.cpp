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

#include "MovementStrategy.h"

namespace corsim {

double RegularMovementStrategy::get_dx(){return _dx;}
double RegularMovementStrategy::get_dy(){return _dy;}

void RegularMovementStrategy::set_dx(double dx){_dx = dx;}
void RegularMovementStrategy::set_dy(double dy){_dy = dy;}


double LockdownMovementStrategy::get_dx(){return _dx;}
double LockdownMovementStrategy::get_dy(){return _dy;}

void LockdownMovementStrategy::set_dx(double dx){_dx = 0;}
void LockdownMovementStrategy::set_dy(double dy){_dy = 0;}
}