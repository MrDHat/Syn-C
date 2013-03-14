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

void queue_ops::push_into_queue(string entry, int identifier){

    if(identifier == 1){
        input_queue.push(entry);
    }

    else if(identifier == 2){
        output_queue.push(entry);        
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