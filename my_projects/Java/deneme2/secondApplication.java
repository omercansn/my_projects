package deneme2;


import java.awt.*;

import java.awt.event.*;

	public class secondApplication implements WindowListener, ActionListener
	{
		private Frame a;
		private Panel b;
		private Label roma, normal;
		private TextField in1,in2;
		private Button convert1, exit;
		
		
		public secondApplication()
		{
			
			a = new Frame();
			b = new Panel();
			roma = new Label("Normal rakam: ");
			b.setLayout(new FlowLayout(FlowLayout.LEADING,5,5));
			b.add(roma);
			in1 = new TextField(30);
			b.add(in1);
			convert1 = new Button("Roma rakamlarına cevir");
			b.add(convert1);
			normal = new Label("Roma rakamı: ");
			b.setLayout(new FlowLayout(FlowLayout.LEADING,5,5));
			b.add(normal);
			in2 = new TextField(30);
			b.add(in2);
			//convert2 = new Button("Normal rakamlara cevir");
			//b.add(convert2);
			exit = new Button("Exit");
			b.add(exit);
			
			b.setBackground(Color.lightGray);
			a.add(b);
			convert1.addActionListener(this);
			//convert2.addActionListener(this);
			exit.addActionListener(this);
			a.addWindowListener(this);
			a.pack();
			
			
			a.setSize(550,200);
			a.setResizable(false);
			a.setVisible(true);
		}
		public static void main(String args[])
		{
			secondApplication uygulama = new secondApplication();
		}
		
		public void actionPerformed(ActionEvent e)
		{
			if(e.getSource()==exit) {
				System.exit(0);
			}
			int NormalSayi=0;	
			String Normal;
			String text1=in1.getText();
			char[] RomanCharacters = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
			int[] Equivalents = {1,5,10,50,100,500,1000};
			try {
				
				if(e.getSource()==convert1) {
					int number=Integer.parseInt(text1);
					if(number>=4000 || number<=0) {
						Frame error= new Frame();
						Panel er = new Panel();
						Label l = new Label("Please enter a number smaller than 4000 or greater than 0!");
						er.add(l);
						er.setBackground(Color.yellow);
						error.add(er);
						error.addWindowListener(this);
						error.pack();
						error.setSize(600,100);
						error.setResizable(false);
						error.setVisible(true);
						return;
					}
					int digit=(int)Math.log10(number)+1;
					int[] digitValues = new int[digit];
					
					for(int i=1; i<=digit; i++) {
						digitValues[i-1] = (number % (int)Math.pow(10, i) / (int)Math.pow(10, i-1)) * (int)Math.pow(10, i-1);
					}
					String Concat = "";
					for(int j=digit;j>0;j--) {
						
						int division = digitValues[j-1]/(int)Math.pow(10,j-1);
						
						if(division==9) {
							Concat += String.valueOf(RomanCharacters[j*2-2]).substring(0,1)+String.valueOf(RomanCharacters[j*2]);
							
						}
						else if(division>=5) {
							Concat += String.valueOf(RomanCharacters[j*2-1]);
							for(int k=1;k<=division-5;k++) {
								Concat += String.valueOf(RomanCharacters[j*2-2]);
								
							}
						}
						else if(division==4) {
							Concat += String.valueOf(RomanCharacters[j*2-2]).substring(0,1)+String.valueOf(RomanCharacters[j*2-1]);
							
						}
						else if(division<4) {
							for(int k=1;k<=division;k++) {
								Concat += String.valueOf(RomanCharacters[j*2-2]);
								
							}
						}
						
						in2.setText(Concat);
					}
				}
			}

			catch(Exception err) {
				Frame error= new Frame();
				Panel er = new Panel();
				Label l = new Label("ERROR!!!");
				er.add(l);
				er.setBackground(Color.red);
				error.add(er);
				error.addWindowListener(this);
				error.pack();
				error.setSize(450,150);
				error.setResizable(false);
				error.setVisible(true);
				
			}
	   
		} 
		
		public void windowOpened(WindowEvent e) {}
		public void windowClosing(WindowEvent e) 
		{
			System.exit(0);
		}
		public void windowClosed(WindowEvent e) {}
		public void windowIconified(WindowEvent e) {}
		public void windowDeiconified(WindowEvent e) {}
		public void windowActivated(WindowEvent e) {}
		public void windowDeactivated(WindowEvent e) {}
		
		
	}
