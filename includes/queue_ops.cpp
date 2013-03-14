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

#include "queue_ops.h"

using namespace std;

queue_ops::queue_ops(){

}

queue_ops::~queue_ops(){

}

void queue_ops::push_into_queue(string entry, int identifier, int direct_flag){
    //Identifier determines the type of queue, 1=> Input Queue | 2=> Output Queue
    //For direct_flag, if=1 => to be inserted directly into the output_queue | if=2 => value to be looked up in hash map | if=3 => A header file

    if(direct_flag == 1){
        if(identifier == 1){
            input_queue.push(entry);
        }

        else if(identifier == 2){
            output_queue.push(entry);        
        }
    }
    else if (direct_flag == 2)  //=> An identifier which cannot be stored directly
    {
        if (identifier == 1)
        {
            //Check for value in hash map
        }
    }
    else if (direct_flag == 3)  //=> A header file
    {
        if (identifier == 1)
        {
            // Code for tackling header file 
        }
    }
}

string queue_ops::pop_from_queue(int identifier){

    if(identifier == 1){
        input_queue.pop();
        popped_str = input_queue.front();
    }
    else if(identifier == 2){
        output_queue.pop();
        popped_str = output_queue.front();
    }
    return popped_str;
}