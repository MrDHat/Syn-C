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

import javax.swing.* ;
import java.awt.*;
import java.awt.event.*;
import java.io.* ;

public class Syn_C implements ActionListener{
	
	String dir = " ", file ;
	static Syn_C obj ;
	JFrame f;
	JLabel br, co ;
	JButton br_b, co_b ;
	
	Syn_C(){
		f = new JFrame("Syn-C") ;
		br = new JLabel(" ",JLabel.CENTER) ;
		br_b = new JButton("BROWSE") ;
		co_b= new JButton("CONVERT") ;
		br_b.addActionListener(this) ;
		co_b.addActionListener(this) ;
		f.setSize(400,150);
		f.setResizable(false) ;
		Container content = f.getContentPane();
		
		content.setLayout(new GridLayout(1,3));
		content.add(br_b);
		content.add(br);
		content.add(co_b);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}

	public static void main(String args[]){
		
			
			obj = new Syn_C() ;

		
	}
	
	public void actionPerformed(ActionEvent ae){
		if(ae.getSource() == br_b){
			FileDialog inp = new FileDialog(f, "Input File...") ;
			inp.setVisible(true) ;
			file = inp.getFile();
			dir = inp.getDirectory();
		}
		
		else{
			if(dir != " "){
				String param  ;
				param = "./a.out " + dir + " " + file ;
				try{
				Process p = Runtime.getRuntime().exec(param) ;
				}
				catch (IOException e) {System.out.println(" procccess not read"+e);}
			}
		}
	}
}
