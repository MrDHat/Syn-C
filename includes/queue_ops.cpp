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
#include <stdio.h>


using namespace std;

queue_ops::queue_ops(){
    parser_obj.xml_reader();
}

queue_ops::~queue_ops(){

}

void queue_ops::push_into_queue(string entry, int direct_flag){
    //For direct_flag, if=1 => to be inserted directly into the output_queue | if=2 => value to be looked up in hash map | if=3 => A header file
    string map_value;
    //printf("Hello") ;
    if(direct_flag == 1){
        input_queue.push(entry);
    }
    else if (direct_flag == 2)  //=> An identifier which cannot be stored directly
    {
        //Check for value in hash map
        map_value= parser_obj.map_find(entry);
        if(map_value!="no")
            input_queue.push(map_value);
        else
            input_queue.push(entry);
    }
    else if (direct_flag == 3)  //=> A header file
    {
            input_queue.push(entry);
    }
    while(!input_queue.empty())
        printf("%s\n", pop_from_queue().c_str());
 }

string queue_ops::pop_from_queue(){
    popped_str = input_queue.front();
    input_queue.pop();
    return popped_str;
}