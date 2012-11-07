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
				String[] param = new String[3] ;
				param[0] = "a.exe " ;
				param[1] = dir ;
				param[2] = file ;
				try{
				Process p = Runtime.getRuntime().exec(param) ;
				}
				catch (IOException e) {System.out.println(" procccess not read"+e);}
			}
		}
	}
}