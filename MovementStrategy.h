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

#pragma once

namespace corsim {

/*
 * Interface for the strategies that define horizontal and 
 * vertical movement of a corsim::Subject
 */
class MovementStrategy
{
    public:
        MovementStrategy(){}
        virtual ~MovementStrategy(){}
        virtual double get_dx() = 0;
        virtual double get_dy() = 0;
        virtual void set_dx(double dx) = 0;
        virtual void set_dy(double dy) = 0;
};


class RegularMovementStrategy : public MovementStrategy
{
    public:
        RegularMovementStrategy(){}
        ~RegularMovementStrategy(){}
        double get_dx();
        double get_dy();
        void set_dx(double dx);
        void set_dy(double dy);
    private:
        double _dx = 0, _dy = 0;
};

class LockdownMovementStrategy : public MovementStrategy
{
    public:
        LockdownMovementStrategy(){}
        ~LockdownMovementStrategy(){}
        double get_dx();
        double get_dy();
        void set_dx(double dx);
        void set_dy(double dy);
    private:
        double _dx = 0, _dy = 0;
};

}