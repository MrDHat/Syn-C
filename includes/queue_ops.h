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
    along with Syn-C.  If not, see <http://www.gnu.org/licenses/>.
*/


/*
Contains Queue functions
*/

#ifndef queue_h__
#define queue_h__

#include <queue>
#include <string>
#include <cstring>
#include "map_generator.h"

using namespace std;

class queue_ops
{
    private:
        queue<string> input_queue, output_queue;
        string popped_str;
        parser parser_obj;
        FILE *output_file;
        string header_array[200];
    
     public:
        static int count;
        queue_ops();
        ~queue_ops();
        void push_into_queue(string entry, int direct_flag); 
        //For direct_flag, if=1 => to be inserted directly into the output_queue | if=2 => value to be looked up in hash map | if=3 => A header file
        string pop_from_queue();
        void generate_output_file(string path);
};

#endif

