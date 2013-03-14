/*
    This file is part of Syn-C.

    Syn-C is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Syn-C is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Weka Grain.  If not, see <http://www.gnu.org/licenses/>.
*/


/*
Contains Queue functions [Works on character pointers instead of std::strings]
*/

#ifndef queue_h__
#define queue_h__

#include <string>
#include <queue>

using namespace std;

class queue_ops
{
    private:
        queue<string> input_queue, output_queue;
        string popped_str;
    public:
        queue_ops();
        ~queue_ops();
        void push_into_queue(string entry, int identifier);  //Identifier determines the type of queue, 1=> Input Queue | 2=> Output Queue
        string pop_from_queue(int identifier);
};

#endif

