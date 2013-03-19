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
		br_b.setSize(100,30);
		br_b.setLocation(150,30);
		co_b= new JButton("CONVERT") ;
		co_b.setSize(100,30);
		co_b.setLocation(150,120);
		br_b.addActionListener(this) ;
		co_b.addActionListener(this) ;
		f.setSize(400,200);
		f.setResizable(false) ;
		Container content = f.getContentPane();
		
		content.setLayout(null);
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
				param = "./flex_output " + dir + " " + file ;
				try{
				Process p = Runtime.getRuntime().exec(param) ;
				}
				catch (IOException e) {System.out.println(" procccess not read"+e);}
			}
		}
	}
}
